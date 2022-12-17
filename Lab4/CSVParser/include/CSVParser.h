//
// Created by Макар Михалёв on 11.12.2022.
//

#ifndef LAB4_CSVPARSER_H
#define LAB4_CSVPARSER_H

#include "include/LazyIterator.h"

template <class... Args>
class CSVParser  {
public:
    CSVParser() = default;

    CSVParser(std::fstream* ptrFile) {
        ptrStream = ptrFile;
        auto t = new std::tuple <Args...>;

        try {
            if (!ptrStream->is_open()) {
                throw std::fstream::failure("File not open\n");
            }
        } catch(const std::fstream::failure& ex) {
            std::cerr << ex.what();
        }
    }

    LazyIterator<Args...>& begin() {
        return LazyIterator<Args...>(ptrStream);
    }

    LazyIterator<Args...>& end() {
        return LazyIterator<Args...>();
    }

    ~CSVParser() {
        ptrStream->close();
    }
private:
    std::fstream* ptrStream;
};

#endif

