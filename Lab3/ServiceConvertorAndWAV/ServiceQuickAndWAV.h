//
// Created by Макар Михалёв on 09.12.2022.
//

#ifndef LAB3_SERVICEQUICKANDWAV_H
#define LAB3_SERVICEQUICKANDWAV_H

#include "ServiceInterfaceConvertorAndWAV.h"

class ServiceQuickAndWAV : public ServiceInterfaceConvertorAndWAV {
public:
    ServiceQuickAndWAV() = default;

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
    ~ServiceQuickAndWAV() = default;
};

namespace FactoryConfigurationRegistration {
    ConfigurationFactoryRegistrations<ServiceQuickAndWAV> _ServiceQuickAndWAV("quick", 3);
}

#endif //LAB3_SERVICEQUICKANDWAV_H
