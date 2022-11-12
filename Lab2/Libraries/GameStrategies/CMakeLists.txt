#add_library(GameStrategies STATIC AlwaysVoiceD/AlwaysVoiceD.h
#                                  AlwaysVoiceD/AlwaysVoiceD.cpp
#                                  AlwaysVoiceC/AlwaysVoiceC.h
#                                  AlwaysVoiceC/AlwaysVoiceC.cpp
#                                  RandomVoice/RandomVoice.h
#                                  RandomVoice/RandomVoice.cpp
#                                  PercentageChoice/PercentageChoice.h
#                                  PercentageChoice/PercentageChoice.cpp
#                                  GameStrategy/GameStrategy.h
#                                  GameStrategy/GameStrategy.cpp
#                                  ViewOpponentsActions/ViewOpponentsActions.cpp
#                                  ViewOpponentsActions/ViewOpponentsActions.h
#                                  BipolarDisorder/BipolarDisorder.h
#                                  BipolarDisorder/BipolarDisorder.cpp)
#
#target_link_libraries(GameMode PUBLIC GameMatrix)
#target_include_directories(GameStrategies PUBLIC ${CMAKE_SOURCE_DIR}/GameMatrix)
#
#target_link_directories(GameStrategies PUBLIC ${CMAKE_BINARY_DIR}/GameMatrix)
