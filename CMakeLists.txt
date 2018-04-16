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

##----------------------------------------------------------------------------##
## Project                                                                    ##
##----------------------------------------------------------------------------##
set(PROJECT acow_c_goodies)
project(${PROJECT})

add_definitions(    
    -DACOW_C_GOODIES_USE_ACOW_ATOX_FUNCTIONS=1
    -DACOW_C_GOODIES_USE_ACOW_ABORT_FUNCTIONS=1
    -DACOW_C_GOODIES_USE_ACOW_SYSTEM_FUNCTIONS=1
    -DACOW_C_GOODIES_USE_ACOW_MEMORY_FUNCTIONS=1
    -DACOW_C_GOODIES_USE_ACOW_MEMORY_CLEAN=1
    -DACOW_C_GOODIES_ENABLE_ASSERTS=1    
    -DACOW_C_GOODIES_USE_ACOW_MEMORY_CLEAN=1      
)


##----------------------------------------------------------------------------##
## Sources                                                                    ##
##----------------------------------------------------------------------------##
##------------------------------------------------------------------------------
## Headers
set(HEADERS
    ## For "std-like" includes.
    acow/stdlib.h 
    ## Library umbrella header.
    acow/c_goodies.h 
    ## Library headers.
    acow/include/Assert/assert.h
    acow/include/Bitwise/bitwise_utils.h
    acow/include/Bitwise/private/bitwise_utils.h
    acow/include/Code/deprecated.h
    acow/include/Code/fake_keywords.h
    acow/include/Code/macros.h
    acow/include/Debug/debugger.h
    acow/include/Debug/private/debugger.h
    acow/include/Discovery/compiler_macros.h
    acow/include/Discovery/cpp_support.h
    acow/include/Discovery/os_macros.h
    acow/include/Discovery/processor_macros.h
    acow/include/Memory/memory.h
    acow/include/Pointers/pointers.h
    acow/include/std/stdlib.h
    acow/include/String/string.h
    acow/include/Types/numeric_types.h
)
##------------------------------------------------------------------------------
## Sources
set(SOURCES
    acow/src/Bitwise/private/bitwise_utils.c
    acow/src/Debug/private/debugger.c
    acow/src/Memory/memory.c
    acow/src/std/stdlib.c
    acow/src/String/string.c
)


##----------------------------------------------------------------------------##
## Library                                                                    ##
##----------------------------------------------------------------------------##
##------------------------------------------------------------------------------
## Lib.
add_library(${PROJECT} ${SOURCES})

##------------------------------------------------------------------------------
## C++ support.
if(CMAKE_CXX_COMPILER)
    SET_SOURCE_FILES_PROPERTIES(${HEADERS} PROPERTIES LANGUAGE CXX)
    SET_SOURCE_FILES_PROPERTIES(${SOURCES} PROPERTIES LANGUAGE CXX)
endif(CMAKE_CXX_COMPILER)

##-----------------------------------------------------------------------------
## Include directories.
target_include_directories(${PROJECT} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
