//
// Created by Макар Михалёв on 06.12.2022.
//

#ifndef LAB3_SERVICEMIXANDWAV_H
#define LAB3_SERVICEMIXANDWAV_H

#include "ServiceInterfaceConvertorAndWAV.h"


class ServiceMixAndWAV : public ServiceInterfaceConvertorAndWAV{
public:
    ServiceMixAndWAV() = default;
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
private:
    WAV* ptrWAV1;
    WAV* ptrWAV2;
};

namespace FactoryConfigurationRegistration {
    ConfigurationFactoryRegistrations<ServiceMixAndWAV> _ServiceMix("mix", 1);
}


#endif //LAB3_SERVICEMIXANDWAV_H
