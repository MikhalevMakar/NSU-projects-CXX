//
// Created by Макар Михалёв on 03.12.2022.
//

#ifndef LAB3_MIX_H
#define LAB3_MIX_H

#include "Convertor.h"

std::string descriptionMixHelp = "\nMix Convertor: \n"
                                   " first parameter file number\n"
                                   "second parameter is the time from which "
                                   "the converter starts working \n";

class Mix : public Convertor {
public:
    Mix() = default;
    void readArg(ConfigurationFile* ptrConfigurationFile) override;
    void changingSamples(uint16_tArray& buffer1,
                         uint16_tArray& buffer2) override;
    int getNumberFile() override;
    int getEndingTime() override;
    int getBeginningTime() override;
    ~Mix() = default;
private:
    void isCorrectArgFile(std::string& inputFileArg1, std::string& inputFileArg2);
    int numberFile;
};

namespace FactoryConfigurationRegistration {
    ConfigurationFactoryRegistrations<Mix> _Mix("mix");
}

ParserRegistration::ParserRegistration MixHelp(descriptionMixHelp);


#endif //LAB3_MIX_H