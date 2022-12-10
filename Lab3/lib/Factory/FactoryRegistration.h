//
// Created by Макар Михалёв on 02.12.2022.
//

#ifndef LAB3_FACTORYREGISTRATION_H
#define LAB3_FACTORYREGISTRATION_H

#include "Factory.h"
#include "../IncludeLibs.h"

namespace FactoryConfigurationRegistration {
    template <typename T>
    class ConfigurationFactoryRegistrations {
    public:
        ConfigurationFactoryRegistrations(std::string  id) {
            Factory::get().registerGeneratorConvertor(
                    id,
                    []() {
                        return static_cast<Convertor*>(new T());
                    });
        }

        ConfigurationFactoryRegistrations(std::string  id, int value) {
            Factory::get().registerGeneratorService(
                    id,
                    []() {
                        return static_cast<ServiceInterfaceConvertorAndWAV*>(new T());
                    });
        }
    };
}

#endif //LAB3_FACTORYREGISTRATION_H
