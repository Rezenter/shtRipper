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

#add_library(caen743 SHARED src/CAEN743.cpp src/CAEN743.h src/root.h include/mds/mdsobjects.h)
#target_link_libraries(caen743 ${CMAKE_CURRENT_SOURCE_DIR}/lib/CAENDigitizer.dll
#        ${CMAKE_CURRENT_SOURCE_DIR}/lib/mds/mdsobjectscppshr.lib)

#add_executable(test src/tester.cpp src/CAEN743.h)
#target_link_libraries(test caen743)
#add_dependencies(test caen743)

#add_executable(copyTree src/copyTreeExample.cpp )
#target_link_libraries(copyTree ${CMAKE_CURRENT_SOURCE_DIR}/lib/mds/mdsobjectscppshr.lib)

#install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libSiSens.so
#        DESTINATION /usr/share/labbot/modules/)


