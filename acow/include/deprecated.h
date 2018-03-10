//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Deprecated.h                                                  //
//  Project   : acow_c_goodies                                                //
//  Date      : Jan 25, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//    Enable a way to us specify that a function is deprecated                //
//---------------------------------------------------------------------------~//

#pragma once

// acow_c_goodies
#include "compiler_macros.h"

//----------------------------------------------------------------------------//
// GCC
#if (ACOW_COMPILER_GCC)
    //COWTODO(n2omatt): Implement for GCC.

//------------------------------------------------------------------------------
// MSVC
#elif (ACOW_COMPILER_MSVC)
    #define ACOW_DEPRECATED(_msg_) __declspec(deprecated(_msg_))

//------------------------------------------------------------------------------
// Unhandled Compiler.
#else
    #pragma error("WARNING: You need to implement DEPRECATED for this compiler")

#endif