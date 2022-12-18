//
// Created by Макар Михалёв on 17.12.2022.
//

#ifndef LAB4_LAZYITERATOR_H
#define LAB4_LAZYITERATOR_H

#include "include/IncludeLibs.h"
#include <algorithm>
#include "include/CSVParser.h"
template<std::size_t> struct int_{};
template <class... Args>
class LazyIterator : public std::iterator<std::input_iterator_tag, std::tuple<Args...>> {
public:
//    typedef std::input_iterator_tag iterator_category;
//    typedef std::tuple<Args...> value_type;
//    typedef ptrdiff_t difference_type;
//    typedef value_type& reference;
//    typedef value_type* pointer;
    using iterator_category = std::input_iterator_tag;
    using value_type = std::tuple<Args...>;
    using difference_type = ptrdiff_t;
    using reference = const value_type&;
    using pointer = const value_type*;
public:
    LazyIterator() = default;
    LazyIterator(int value) : ptrStream(NULL) {}
    LazyIterator(std::fstream* ptrFile) : ptrStream(ptrFile) {}
    LazyIterator(LazyIterator& it) : value_type(it.value_type) { }

    bool operator==(LazyIterator& other) {
        return (this->ptrStream == other.ptrStream);
    }

    bool operator!=(LazyIterator& other) {
        return !(this == other);
    }

    reference operator*() {
        return tupleValue;
    }

    LazyIterator<Args...>& operator++() {
        *ptrStream >> tupleValue;
        return *this;
    }

    void readTuple(std::stringstream& ss, std::tuple<Args...>& tuple,  int cur_pos, int_<sizeof...(Args)>) { }

    template<std::size_t Size>
    void readTuple(std::stringstream& ss, std::tuple<Args...>& tuple, int cur_pos,int_<Size>) {
        std::string line;
        if(Size == sizeof...(Args)) return;
        std::tuple_element_t<Size, std::tuple<Args...>> value;
        getline(ss, line, c);
        std::istringstream(line) >> value;
        get<Size>(tuple) = value;
        readTuple(ss, tuple, cur_pos,int_<Size+1>());
    }

    //friend std::ifstream& operator>>(std::ifstream &is, std::tuple<Args...>& tuple);
private:
    char c = ';';
    std::fstream* ptrStream;
     std::tuple<Args...> tupleValue;
};

//Input line convert to tuple

template <class... Args>
std::ifstream& operator>>(std::ifstream &is, std::tuple<Args...>& tuple) {
    std::string line;
    getline(is, line);
    std::stringstream ss{std::move(line)};
    LazyIterator<Args...> lazyIterator;
    lazyIterator.readTuple(ss, tuple, 0,int_<0>());
    return is;
}

//Output tuple
template <class Tuple>
std::ostream&  printTuple(std::ostream& output, const Tuple& tuple, int_<1>) {
    return output << std::get<std::tuple_size<Tuple>::value-1>(tuple)
                  << std::endl;
}

template <class Tuple, std::size_t Size>
std::ostream& printTuple(std::ostream& output, const Tuple& tuple, int_<Size>) {
    output << std::get<std::tuple_size<Tuple>::value-Size>(tuple) << " ";
    return printTuple(output, tuple, int_<Size-1>());
}

template <class... Args>
std::ostream& operator<<(std::ostream& output,
                         const std::tuple<Args...>& tuple) {
    return printTuple(output, tuple, int_<sizeof...(Args)>());
}



//template <typename Head, typename ...Tail>
//std::tuple <Head, Tail...> read_tuple(std::ifstream &is) {
//    Head head;
//    is.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
//    try {
//        is >> head;
//    }
//    catch (std::ifstream::failure &e) {
//        if (is.eof()) {
//            return std::tuple<Head, Tail...>{};
//        }
//        std::cerr << "EXCEPTION: wrong format\n";
//        exit(1);
//    }
//
//    if constexpr (sizeof...(Tail) == 0) {
//        return std::tuple{head};
//    }
//    else {
//        return std::tuple_cat(std::tuple{head}, read_tuple<Tail...>(is));
//    }
//}
//
//template <typename ...Args>
//std::ifstream& operator>> (std::ifstream &is, std::tuple <Args...> &t) {
//    t = read_tuple<Args...>(is);
//    return is;
//}

#endif //LAB4_LAZYITERATOR_H
