//
// Created by Макар Михалёв on 17.12.2022.
//

#ifndef LAB4_PRINTTUPLE_H
#define LAB4_PRINTTUPLE_H

#include "include/IncludeLibs.h"
#include <algorithm>
#include "include/CSVParser.h"
template<std::size_t> struct int_{};

template <class Tuple>
std::ostream&  printTuple(std::ostream& output, const Tuple& tuple, int_<1>) {
    return output << std::get<std::tuple_size<Tuple>::value-1>(tuple);
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
#endif //LAB4_PRINTTUPLE_H
