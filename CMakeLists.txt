cmake_minimum_required(VERSION 3.23)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex4
        Server/AbstractDefaultIO.cpp
        Server/AbstractDefaultIO.h
        Server/StandardIO.cpp
        Server/StandardIO.h
        Server/Commander.cpp
        Server/Commander.h Server/UploadFile.cpp Server/UploadFile.h Server/RelativeVector.cpp Server/RelativeVector.h)

