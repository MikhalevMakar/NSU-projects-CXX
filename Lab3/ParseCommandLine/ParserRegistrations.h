//
// Created by Макар Михалёв on 10.12.2022.
//

#ifndef LAB3_PARSERREGISTRATIONS_H
#define LAB3_PARSERREGISTRATIONS_H

#include "ParseCommandLine.h"

namespace ParserRegistration {
    class ParserRegistration {
    public:
        ParserRegistration() = default;

        ParserRegistration(const std::string description) {
            ParseCommandLine::Instance().ParserRegistration(description);
        }
    };
}

#endif //LAB3_PARSERREGISTRATIONS_H
