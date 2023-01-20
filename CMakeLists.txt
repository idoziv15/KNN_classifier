cmake_minimum_required(VERSION 3.20)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex4
        IO/AbstractDefaultIO.cpp
        IO/AbstractDefaultIO.h
        IO/StandardIO.cpp
        IO/StandardIO.h
        Server/Commands/Commander.cpp
        Server/Commands/Commander.h Server/Commands/UploadFile.cpp
        Server/Commands/UploadFile.h
        Server/DataAndAssistance/RelativeVector.cpp
        Server/DataAndAssistance/RelativeVector.h
        Server/DataAndAssistance/ClassifiedRelativeVector.cpp
        Server/DataAndAssistance/ClassifiedRelativeVector.h
        Server/DataAndAssistance/DataProcessing.cpp Server/DataAndAssistance/DataProcessing.h
        Server/DataAndAssistance/ServerValidations.cpp
        Server/DataAndAssistance/RelativeDatabase.cpp Server/DataAndAssistance/RelativeDatabase.h Server/Commands/AlgorithmSetting.cpp Server/Commands/AlgorithmSetting.h Server/Commands/ClassifyData.cpp Server/Commands/ClassifyData.h Server/Distances/Taxicab.h Server/Distances/Taxicab.cpp Server/Distances/Minkowski.h Server/Distances/Minkowski.cpp Server/Distances/Euclidean.h Server/Distances/Chebyshev.h Server/Distances/Euclidean.cpp Server/Distances/Chebyshev.cpp Server/Distances/Canberra.h Server/Distances/Canberra.cpp Server/Distances/AbstractDistance.h Server/Distances/AbstractDistance.cpp Server/DataAndAssistance/KnnAlgorithm.cpp Server/DataAndAssistance/KnnAlgorithm.h Server/Commands/SendData.cpp Server/Commands/SendData.h Server/Commands/SendToDownload.cpp Server/Commands/SendToDownload.h Server/Commands/EndConnection.cpp Server/Commands/EndConnection.h Server/main.cpp Server/ServerFlow/CLI.cpp Server/ServerFlow/CLI.h Client/ClientManagement.cpp
       Client/DataAndCalcs/ClientValidation.h Client/DataAndCalcs/ClientValidation.cpp
        Client/Operations/UploadFilesOp.cpp
        Client/Operations/UploadFilesOp.h
        Client/Operations/AbstractOperations.h
        Client/Operations/AbstractOperations.cpp
        Client/Operations/AlgorithmSettingOp.h
        Client/Operations/AlgorithmSettingOp.cpp
        Client/Operations/DisplayResult.h
        Client/Operations/DisplayResult.cpp)

