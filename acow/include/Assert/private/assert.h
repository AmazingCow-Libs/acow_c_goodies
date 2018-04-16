//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : PrivateHelpers.h                                              //
//  Project   : CoreAssert                                                    //
//  Date      : Dec 14, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// std
#include <stdarg.h>
#include <string.h>
// acow_c_goodies
#include "acow/include/Discovery/cpp_support.h"


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
ACOW_EXTERN_C char*
_acow_assert_private_join_args(const char *fmt, ...) ACOW_CPP_NOEXCEPT;

ACOW_EXTERN_C void
_acow_assert_private_print_args(
    const    char   *expr,
    const    char   *file,
    unsigned int     line,
    const    char   *func,
    const    char   *msg,
    ...) ACOW_CPP_NOEXCEPT;
