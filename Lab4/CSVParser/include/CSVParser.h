//
// Created by Макар Михалёв on 11.12.2022.
//

#ifndef LAB4_CSVPARSER_H
#define LAB4_CSVPARSER_H

#include "include/PrintTuple.h"

template <class... Args>

class CSVParser {
private:
    std::tuple<Args...> tuple;
    char c = ';';
    std::ifstream* file;
public:
    CSVParser() = default;

    CSVParser(std::ifstream* file_) {
        file = file_;
        try {
            if (!file->is_open()) {
                throw std::fstream::failure("File not open\n");
            }
        } catch(const std::fstream::failure& ex) {
            std::cerr << ex.what();
        }
        this->fillTuple();
    }

    template <class Iter>
    class LazyIterator {
    private:
        typedef Iter iterator_type;
        typedef std::input_iterator_tag iterator_category;
        typedef std::tuple<iterator_type> value_type;
        typedef ptrdiff_t difference_type;
        typedef iterator_type& reference;
        typedef value_type* pointer;
        iterator_type* value;
    public:
        friend class CSVParser;
        LazyIterator() = default;
        LazyIterator(Iter* iter) : value(iter) { }
        LazyIterator(LazyIterator& it) : value(it.value){ }

        bool operator==(const LazyIterator& other)   {
            return (value == other.value);
        }

        bool operator!=(const LazyIterator& other) {
            return !(*this == other);
        }

        reference operator*() {
            return *value;
        }

        LazyIterator& operator++() {
            if (value->file->eof())  {
                *this = nullptr;
                return *this;
            }
            value->fillTuple();
            return *this;
        }
    };

private:
    typedef LazyIterator<CSVParser> lazyIterator;
    typedef LazyIterator<CSVParser> constLazyIterator;
public:
    lazyIterator begin()  {
        CSVParser<Args...>* csvParser = this;
        return lazyIterator(csvParser);
    }

    lazyIterator end()  {
        return NULL;
    }

    constLazyIterator begin()  const {
        CSVParser<Args...>* csvParser = this;
        return constLazyIterator(csvParser);
    }

    constLazyIterator end()  const {
        return NULL;
    }

    friend std::ostream& operator<<(std::ostream& output, const CSVParser& csvParser) {
        return output << csvParser.tuple << '\n';
    }

private:
    void readTuple(std::stringstream& ss, std::tuple<Args...>& tuple,  int cur_pos, int_<sizeof...(Args)>) { }

    template<std::size_t Size>
    void readTuple(std::stringstream& ss, std::tuple<Args...>& tuple, int cur_pos,int_<Size>) {
        std::string line;
        std::tuple_element_t<Size, std::tuple<Args...>> value;
        getline(ss, line, c);
        std::istringstream(line) >> value;
        get<Size>(tuple) = value;
        readTuple(ss, tuple, cur_pos,int_<Size+1>());
    }

    void fillTuple() {
        std::string line;
        getline(*file, line);
        std::stringstream ss{std::move(line)};
        this->readTuple(ss, tuple, 0, int_<0>());
    }
};

#endif

