##~---------------------------------------------------------------------------##
##                     _______  _______  _______  _     _                     ##
##                    |   _   ||       ||       || | _ | |                    ##
##                    |  |_|  ||       ||   _   || || || |                    ##
##                    |       ||       ||  | |  ||       |                    ##
##                    |       ||      _||  |_|  ||       |                    ##
##                    |   _   ||     |_ |       ||   _   |                    ##
##                    |__| |__||_______||_______||__| |__|                    ##
##                             www.amazingcow.com                             ##
##  File      : CMakeLists.txt                                                ##
##  Project   : acow_c_goodies                                                ##
##  Date      : Mar 10, 2018                                                  ##
##  License   : GPLv3                                                         ##
##  Author    : n2omatt <n2omatt@amazingcow.com>                              ##
##  Copyright : AmazingCow - 2018                                             ##
##                                                                            ##
##  Description :                                                             ##
##                                                                            ##
##---------------------------------------------------------------------------~##

cmake_minimum_required(VERSION 3.5)

##------------------------------------------------------------------------------
## Project Settings.
project(acow_c_goodies)


##------------------------------------------------------------------------------
## Sources.
set(HEADERS
    acow/stdlib.h
    acow/include/stdlib.h
    acow/include/processor_macros.h
    acow/include/private/bitwise_utils.h
    acow/include/cpp_support.h
    acow/include/deprecated.h
    acow/include/compiler_macros.h
    acow/include/pointers.h
    acow/include/debugger.h
    acow/include/bitwise_utils.h
    acow/include/fake_keywords.h
    acow/include/os_macros.h
    acow/include/numeric_types.h
    acow/include/memory.h
    acow/c_goodies.h
)

set(SOURCES
    acow/src/private/bitwise_utils.c
    acow/src/debugger.c
    acow/src/memory.c
    acow/src/stdlib.c
)

add_library(acow_c_goodies ${SOURCES})

if(CMAKE_CXX_COMPILER)
    SET_SOURCE_FILES_PROPERTIES(${HEADERS} PROPERTIES LANGUAGE CXX)
    SET_SOURCE_FILES_PROPERTIES(${SOURCES} PROPERTIES LANGUAGE CXX)
endif(CMAKE_CXX_COMPILER)


##------------------------------------------------------------------------------
## Include directories.
target_include_directories(acow_c_goodies PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


##------------------------------------------------------------------------------
## Dependecies.
target_link_libraries(acow_c_goodies LINK_PUBLIC CoreAssert)
