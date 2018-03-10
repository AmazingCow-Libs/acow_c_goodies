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
## AmazingCow Libs
add_subdirectory(lib/CoreAssert)


##------------------------------------------------------------------------------
## Sources.
add_library(acow_c_goodies
    acow/src/private/bitwise_utils.c
    acow/src/debugger.c
    acow/src/memory.c
    acow/src/stdlib.c
)

##------------------------------------------------------------------------------
## Include directories.
target_include_directories(acow_c_goodies PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(acow_c_goodies PUBLIC lib/CoreAssert)

##------------------------------------------------------------------------------
## Dependecies.
target_link_libraries(acow_c_goodies LINK_PUBLIC CoreAssert)
