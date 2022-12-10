//
// Created by Макар Михалёв on 02.12.2022.
//

#ifndef LAB3_FACTORY_H
#define LAB3_FACTORY_H

#include "../IncludeLibs.h"

class Convertor;
typedef Convertor*(*СonvertorInstanceGenerator)();

class ServiceInterfaceConvertorAndWAV;
typedef ServiceInterfaceConvertorAndWAV*(*ServiceInstanceGenerator)();

class Factory {
public:
    static Factory& get();
    Convertor* orderСonvertor(std::string typeName);
    bool registerGeneratorConvertor(std::string  typeName, const СonvertorInstanceGenerator& funcCreate);

    ServiceInterfaceConvertorAndWAV* orderService(std::string typeName);
    bool registerGeneratorService(std::string  typeName, const ServiceInstanceGenerator& funcCreate);

    Factory() = default;
    ~Factory() = default;
    std::unordered_map<std::string, СonvertorInstanceGenerator> s_generatorsConvertor;
    std::unordered_map<std::string, ServiceInstanceGenerator> s_generatorsService;
};


#endif //LAB3_FACTORY_H
