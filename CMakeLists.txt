cmake_minimum_required(VERSION 3.23)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex4
        Server/IO/AbstractDefaultIO.cpp
        Server/IO/AbstractDefaultIO.h
        Server/IO/StandardIO.cpp
        Server/IO/StandardIO.h
        Server/Commands/Commander.cpp
        Server/Commands/Commander.h Server/Commands/UploadFile.cpp Server/Commands/UploadFile.h Server/DataAndAssistance/RelativeVector.cpp Server/DataAndAssistance/RelativeVector.h Server/DataAndAssistance/ClassifiedRelativeVector.cpp Server/DataAndAssistance/ClassifiedRelativeVector.h Server/DataAndAssistance/DataProcessing.cpp Server/DataAndAssistance/DataProcessing.h Server/DataAndAssistance/ServerValidations.cpp Server/DataAndAssistance/RelativeDatabase.cpp Server/DataAndAssistance/RelativeDatabase.h Server/Commands/AlgorithmSetting.cpp Server/Commands/AlgorithmSetting.h)

