#include <iostream>
#include <string>

template<std::size_t> struct int_{};

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

int main() {
    std::tuple<int, std::string> t1{42, "C++|"};
    auto t2 = std::make_tuple(232, "e3wd");

    std::string b;
    int a = 3;
    auto t3 = std::tie(a, b);


    std::cout << t1;
    return 0;
}
