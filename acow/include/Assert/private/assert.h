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
//------------------------------------------------------------------------------
// Print the Assertion message and abort.
ACOW_EXTERN_C void
_acow_assert_private_print_assertion_and_abort(
    const    char   *pExpressionStr,
    const    char   *pFileStr,
    unsigned int     line,
    const    char   *pFunctionStr,
    const    char   *pDetailMessageFmt,
    ...) ACOW_CPP_NOEXCEPT;


//------------------------------------------------------------------------------
// Print the Unreachable message and abort.
ACOW_EXTERN_C void
_acow_assert_private_print_unreachable_and_abort(
    const    char *pFileStr,
    unsigned int   line,
    const    char *pFunctionStr,
    const    char *pDetailMessageFmt,
    ...) ACOW_CPP_NOEXCEPT;