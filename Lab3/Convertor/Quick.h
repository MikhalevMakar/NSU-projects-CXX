//
// Created by Макар Михалёв on 09.12.2022.
//

#ifndef LAB3_QUICK_H
#define LAB3_QUICK_H

#include "Convertor.h"

class Quick : public Convertor{
public:
    void readArg(ConfigurationFile* ptrConfigurationFile) override;
    void changingSamples(uint16_tArray& buffer1,
                         uint16_tArray& buffer2) override;
    int getNumberFile() override;
    int getEndingTime() override;
    int getBeginningTime() override;
private:
    int timeEnd, valueQuick, length;
};

namespace FactoryConfigurationRegistration{
    ConfigurationFactoryRegistrations<Quick> _Quick("quick");
}

#endif //LAB3_QUICK_H