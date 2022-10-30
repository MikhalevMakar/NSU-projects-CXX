add_library(GameStrategies STATIC AlwaysVoiceD.h
                                  AlwaysVoiceD.cpp
                                  AlwaysVoiceC.h
                                  AlwaysVoiceC.cpp
                                  RandomVoice.h
                                  RandomVoice.cpp
                                  GameStrategy.h
                                  StrategyFactory.h
                                  StrategyFactory.cpp
                                  PercentageChoice.h
                                  PercentageChoice.cpp)



target_include_directories(GameStrategies PUBLIC ${CMAKE_BINARY_DIR}/GameMatrix)

target_link_directories(GameStrategies PUBLIC ${CMAKE_BINARY_DIR}/GameMatrix)

