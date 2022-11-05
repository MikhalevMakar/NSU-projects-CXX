add_library(GameStrategies STATIC AlwaysVoiceD/AlwaysVoiceD.h
        AlwaysVoiceD/AlwaysVoiceD.cpp
        AlwaysVoiceC/AlwaysVoiceC.h
        AlwaysVoiceC/AlwaysVoiceC.cpp
        RandomVoice/RandomVoice.h
        RandomVoice/RandomVoice.cpp
        GameStrategy/GameStrategy.h
        StrategyFactory/StrategyFactory.h
        StrategyFactory/StrategyFactory.cpp
        PercentageChoice/PercentageChoice.h
        PercentageChoice/PercentageChoice.cpp
        GameStrategy/GameStrategy.h
        GameStrategy/GameStrategy.cpp
        ViewOpponentsActions/ViewOpponentsActions.cpp
        ViewOpponentsActions/ViewOpponentsActions.h
        BipolarDisorder/BipolarDisorder.h
        BipolarDisorder/BipolarDisorder.cpp
        CollectiveStrategy/CollectiveStrategy.h
        CollectiveStrategy/CollectiveStrategy.cpp
        CollectiveStrategy/Factory.h
        CollectiveStrategy/Factory.cpp)


target_include_directories(GameStrategies PUBLIC ${CMAKE_SOURCE_DIR}/GameMatrix)

target_include_directories(GameStrategies PUBLIC ${CMAKE_BINARY_DIR}/GameMatrix)

target_link_directories(GameStrategies PUBLIC ${CMAKE_BINARY_DIR}/GameMatrix)

