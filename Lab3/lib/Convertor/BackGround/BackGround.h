//
// Created by Макар Михалёв on 09.12.2022.
//

#ifndef LAB3_BACKGROUND_H
#define LAB3_BACKGROUND_H

#include "Convertor.h"

std::string descriptionBackGroundHelp = "\nBackGround Convertor: \n"
                                   " first parameter file number second parameter "
                                   "is the time from which the converter starts working \n "
                                   "third parameter end time\n";

class BackGround : public Convertor{
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
    ConfigurationFactoryRegistrations<BackGround> _BackGround("backGround");
}

ParserRegistration::ParserRegistration BackGroundHelp(descriptionBackGroundHelp);


#endif //LAB3_BACKGROUND_H
