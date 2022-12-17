//
// Created by Макар Михалёв on 17.12.2022.
//

#ifndef LAB4_LAZYITERATOR_H
#define LAB4_LAZYITERATOR_H

#include "include/IncludeLibs.h"

template <class... Args>
class LazyIterator {
public:
    typedef std::input_iterator_tag iterator_category;
    typedef std::tuple<Args...> value_type;
    typedef ptrdiff_t difference_type;
    typedef value_type& reference;
    typedef value_type* pointer;
public:
    LazyIterator() : ptrStream(NULL) {}
    LazyIterator( std::fstream* ptrFile) : ptrStream(ptrFile) {}

    LazyIterator(const LazyIterator& it) : value_type(it.value_type) { }

    bool operator==(LazyIterator& other) {
        return (this->ptrStream == other.ptrStream);
    }

    bool operator!=(LazyIterator& other) {
        return !(this == other);
    }

    reference operator*() {
        return value;
    }

    LazyIterator<Args...>& operator++() {
        return *this;
    }

private:
    std::fstream* ptrStream;
    std::tuple<Args...> value;

};
template<std::size_t> struct int_{};

//Input line convert to tuple
//template <class Tuple>
//std::ifstream&  readTuple(std::stringstream ss, Tuple& tuple, int_<1>) {
//    return
//}

template <class Tuple, typename ...Args, std::size_t Size>
std::ifstream& readTuple(std::stringstream ss, Tuple& tuple, int_<Size>) {

    return readTuple(ss, tuple, int_<Size-1>());
}

template <typename ...Args>
std::ifstream& operator>>(std::ifstream &is, std::tuple <Args...> &tuple) {
    std::string line;
    getline(is, line);
    std::stringstream ss{std::move(line)};
    std::cout << sizeof...(Args);
    //readTuple<Args...>(ss, tuple, int_<sizeof...(Args)>())
    return is;
}

//Output tuple
template <class Tuple>
std::ostream&  print_tuple(std::ostream& output, const Tuple& tuple, int_<1>) {
    return output << std::get<std::tuple_size<Tuple>::value-1>(tuple)
                  << std::endl;
}

template <class Tuple, std::size_t Size>
std::ostream& print_tuple(std::ostream& output, const Tuple& tuple, int_<Size>) {
    output << std::get<std::tuple_size<Tuple>::value-Size>(tuple) << " ";
    return print_tuple(output, tuple, int_<Size-1>());
}

template <class... Args>
std::ostream& operator<<(std::ostream& output,
                         const std::tuple<Args...>& tuple) {

    return print_tuple(output, tuple, int_<sizeof...(Args)>());
}

#endif //LAB4_LAZYITERATOR_H
