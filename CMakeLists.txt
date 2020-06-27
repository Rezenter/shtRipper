cmake_minimum_required(VERSION 3.16)
project(shtRipper)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)


include_directories(${CMAKE_SOURCE_DIR} include src)

add_custom_target(
        auto_increment_version
        ${CMAKE_COMMAND}
        -D VERSION_FILE=${CMAKE_SOURCE_DIR}/version.h
        -P ${CMAKE_SOURCE_DIR}/AutoVersion.cmake
)

add_executable(tester src/tester.cpp version.h src/niifaFile.cpp)
add_dependencies(tester auto_increment_version)

