cmake_minimum_required(VERSION 3.5)
project(AdvenCore VERSION 1.0.0 LANGUAGES CXX ASM)

set(CPACK_PACKAGE_NAME libadvencore)
set(CPACK_PACKAGE_VENDOR placeholder)
set(CPACK_PACKAGE_CONTACT placeholder)

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/external/CmakeStuff/.git)
    execute_process(COMMAND git submodule update --init -- external/CmakeStuff
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/external/CmakeStuff)

include(CPack)
include(GNUInstallDirs)

find_package(tonc)

add_library(advencore
    source/Backgrounds.cpp
    source/Display.cpp
    source/Input.cpp
    source/Object.cpp
    source/VBAPrint.s
    source/Vector.cpp
    source/Timers.cpp
    source/SRAM.cpp
    source/ScreenEntry.cpp
    source/LinkMultiplayer.cpp
    source/LinkNormal.cpp
    include/advenCore/LinkNormal.hpp
    include/advenCore/Backgrounds.hpp
    include/advenCore/ScreenEntry.hpp
    include/advenCore/Property.hpp
    include/advenCore/Timers.hpp
    include/advenCore/Object.hpp
    include/advenCore/BitField.hpp
    include/advenCore/HwUtils.hpp
    include/advenCore/Types.hpp
    include/advenCore/VBAPrint.hpp
    include/advenCore/SRAM.hpp
    include/advenCore/Display.hpp
    include/advenCore/Input.hpp
    include/advenCore/Vector.hpp
    include/advenCore/LinkMultiplayer.hpp
    include/advenCore/SystemCall.hpp
    source/SystemCall.s
    include/advenCore/macros/Property.hpp
)

target_include_directories(advencore
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/include/advenCore
)
target_link_libraries(advencore tonc)

#For instalation of static library files.
install(TARGETS advencore tonc
    EXPORT advencore-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
#For instalation of include files.
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
#For installation of CMake config files. For find_package().
install(EXPORT advencore-config DESTINATION ${CMAKE_INSTALL_DATADIR}/advencore)