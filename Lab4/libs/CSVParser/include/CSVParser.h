//
// Created by Макар Михалёв on 11.12.2022.
//

#ifndef LAB4_CSVPARSER_H
#define LAB4_CSVPARSER_H

#include "include/PrintTuple.h"
#include "ExceptionsParserCSV.h"

template <class... Args>
class CSVParser {
private:
    std::tuple<Args...> tuple;
    char columnDelim,
         rowDelim,
         shielding;
    std::ifstream* file;
    std::string line;
    int indexReadRow = 0;

    void  escapeSymbols(int countSkip) {
        for(int i = 0; i < countSkip; ++i) {
            getline(*file, line);
            if(file->eof()) {
                throw ExceptionsFilePermission(indexReadRow, line.size());
            }
        }
    }
public:
    CSVParser() = delete;

    CSVParser(std::ifstream* file_,
              int countSkip = 0,
              char columnDelim_ = ',',
              char rowDelim_ = '\n',
              char shielding_ = '"') : columnDelim(columnDelim_),
                                       rowDelim(rowDelim_),
                                       shielding(shielding_) {
        file = file_;
        try {
            if (!file->is_open()) {
                throw std::fstream::failure("File not open\n");
            }
        } catch(const std::fstream::failure& ex) {
            std::cerr << ex.what();
        }

        escapeSymbols(countSkip);
        this->fillTuple();
        ++indexReadRow;
    }

    template <class Iter>
    class LazyIterator {
        friend CSVParser;
    private:
        typedef Iter iterator_type;
        typedef std::input_iterator_tag iterator_category;
        typedef std::tuple<iterator_type> value_type;
        typedef iterator_type& reference;
        typedef value_type* pointer;
        iterator_type* value;
    public:
        friend class CSVParser;
        LazyIterator() = default;
        LazyIterator(LazyIterator& it) : value(it.value){ }
        LazyIterator(Iter* iter) : value(iter) { }

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
public:
    lazyIterator begin()  {
        CSVParser<Args...>* csvParser = this;
        return lazyIterator(csvParser);
    }

    lazyIterator end()  {
        return NULL;
    }

    friend std::ostream& operator<<(std::ostream& output, const CSVParser& csvParser) {
        return output << csvParser.tuple << std::endl;
    }

private:
    void ChangeLine() {
        if(line[0] == shielding) {
            line.erase(line.begin());
        }
        if(line[line.size()-1] == shielding) {
            line.erase(line.end()-1);
        }
        if(!line.size()) throw ErrorInputFileData(indexReadRow, line.size());
    }

    void readTuple(std::stringstream& ss, std::tuple<Args...>& tuple,  int cur_pos, int_<sizeof...(Args)>) { }

    template<std::size_t Size>
    void readTuple(std::stringstream& ss, std::tuple<Args...>& tuple, int cur_pos, int_<Size>) {
        line.clear();
        std::tuple_element_t<Size, std::tuple<Args...>> value;
        getline(ss, line, columnDelim);
        ChangeLine();
        if(line.empty()) throw ExceptionsReadThread(indexReadRow, line.size());
        std::istringstream(line) >> value;
        get<Size>(tuple) = value;
        readTuple(ss, tuple, cur_pos,int_<Size+1>());
    }

    void fillTuple() {
        line.clear();
        getline(*file, line, rowDelim);
        ++indexReadRow;
        std::stringstream ss{std::move(line)};
        if(ss.eof()) throw ErrorInputFileData(indexReadRow, line.size());
        this->readTuple(ss, tuple, 0, int_<0>());
    }
};

#endif

