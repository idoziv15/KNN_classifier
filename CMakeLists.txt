cmake_minimum_required(VERSION 3.20)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

file(GLOB_RECURSE SERVER_SOURCES "Server/*.cpp" "Server/*.h")

file(GLOB_RECURSE CLIENT_SOURCES "Client/*.cpp" "Client/*.h")

file(GLOB_RECURSE IO_SOURCES "IO/*.cpp" "IO/*.h")

# server executable
add_executable(ex4_server ${SERVER_SOURCES} ${IO_SOURCES})

# client executable
add_executable(ex4_client ${CLIENT_SOU1RCES} ${IO_SOURCES})