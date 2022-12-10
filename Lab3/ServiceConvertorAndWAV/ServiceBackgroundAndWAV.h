//
// Created by Макар Михалёв on 09.12.2022.
//

#ifndef LAB3_SERVICEBACKGROUNDANDWAV_H
#define LAB3_SERVICEBACKGROUNDANDWAV_H

#include "ServiceInterfaceConvertorAndWAV.h"

class ServiceBackgroundAndWAV : public ServiceInterfaceConvertorAndWAV {
public:
    ServiceBackgroundAndWAV() = default;

    void firstLaunchConvertorAndWAV(ParseCommandLine* ptrParseCommandLine,
                                    Convertor* ptrConvertor,
                                    std::vector<std::string> vectorInputFile,
                                    ConfigurationFile* ptrConfigurationFile,
                                    WAV* ptrWAV) override;

    void linkConvertorAndWAV(ParseCommandLine* ptrParseCommandLine,
                             Convertor* ptrConvertor,
                             std::vector<std::string> vectorInputFile,
                             ConfigurationFile* ptrConfigurationFile,
                             WAV* ptrWAV) override;
    ~ServiceBackgroundAndWAV() = default;
};

namespace FactoryConfigurationRegistration {
    ConfigurationFactoryRegistrations<ServiceBackgroundAndWAV> _ServiceBackgroundAndWAV("backGround", 4);
}

#endif //LAB3_SERVICEBACKGROUNDANDWAV_H
