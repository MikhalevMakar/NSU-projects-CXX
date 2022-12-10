//
// Created by Макар Михалёв on 30.11.2022.
//

#include "Convertor.h"

bool Convertor::is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}