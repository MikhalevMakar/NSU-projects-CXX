//
// Created by Макар Михалёв on 06.12.2022.
//

#ifndef LAB3_SERVICEMUTEANDWAV_H
#define LAB3_SERVICEMUTEANDWAV_H

#include "ServiceInterfaceConvertorAndWAV.h"

class ServiceMuteAndWAV : public ServiceInterfaceConvertorAndWAV {
public:
    ServiceMuteAndWAV() = default;
    void linkConvertorAndWAV(ParseCommandLine* ptrParseCommandLine,
                             Convertor* ptrConvertor,
                             std::vector<std::string> vectorInputFile,
                             ConfigurationFile* ptrConfigurationFile,
                             WAV* ptrWAV) override;
    ~ServiceMuteAndWAV() = default;
};

namespace FactoryConfigurationRegistration {
    ConfigurationFactoryRegistrations<ServiceMuteAndWAV> _ServiceMute("mute", 2);
}


#endif //LAB3_SERVICEMUTEANDWAV_H
