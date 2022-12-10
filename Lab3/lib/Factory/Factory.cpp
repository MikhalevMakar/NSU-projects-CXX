//
// Created by Макар Михалёв on 02.12.2022.
//

#include "Factory.h"

Factory& Factory::get() {
    static Factory instance;
    return instance;
}

Convertor* Factory::orderСonvertor(std::string typeName) {
    auto it = s_generatorsConvertor.find(typeName);
    if (it != s_generatorsConvertor.end())
        return it->second();
    throw std::invalid_argument("This convertor  not found\n");
}

bool Factory::registerGeneratorConvertor(std::string typeName, const СonvertorInstanceGenerator& funcCreate) {
    return s_generatorsConvertor.insert(std::make_pair(typeName, funcCreate)).second;
}


ServiceInterfaceConvertorAndWAV* Factory::orderService(std::string typeName) {
    auto it = s_generatorsService.find(typeName);
    if (it != s_generatorsService.end())
        return it->second();
    throw std::invalid_argument("This service convertor  not found\n");
}

bool Factory::registerGeneratorService(std::string  typeName, const ServiceInstanceGenerator& funcCreate) {
    return s_generatorsService.insert(std::make_pair(typeName, funcCreate)).second;
}