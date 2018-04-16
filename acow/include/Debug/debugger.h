//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Debugger.h                                                    //
//  Project   : acow_cpp_goodies                                              //
//  Date      : Feb 23, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// acow_c_goodies
#include "acow/include/Discovery/cpp_support.h"
#include "acow/include/Types/numeric_types.h"
// acow_c_goodies - Private
#include "private/debugger.h"


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
bool acow_is_debugger_present() ACOW_CPP_NOEXCEPT;

//----------------------------------------------------------------------------//
// Macros                                                                     //
//----------------------------------------------------------------------------//
// COWTODO(n2omatt): Works on GNU/Linux... abstract for other platforms...
#define ACOW_DEBUGGER_BREAK() \
    _ACOW_PRIV_ACOW_DEBUGGER_BREAK()
 
