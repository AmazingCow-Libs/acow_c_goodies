//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : BitwiseUtils.h                                                //
//  Project   : acow_c_goodies                                                //
//  Date      : Feb 23, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// std
#include <stdarg.h>

//------------------------------------------------------------------------------
// Private stuff...
//   Should not be used by consumers of this lib.
#include "private/bitwise_utils.h"


//----------------------------------------------------------------------------//
// Add / Remove                                                               //
//----------------------------------------------------------------------------//
#define ACOW_FLAG_ADD(_what_, _var_) \
    _ACOW_PRIV_ACOW_FLAG_ADD(_what_, _var_)

#define ACOW_FLAG_REMOVE(_what_, _var_) \
    _ACOW_PRIV_ACOW_FLAG_REMOVE(_what_, _var_)


//----------------------------------------------------------------------------//
// Has                                                                        //
//----------------------------------------------------------------------------//
#define ACOW_FLAG_HAS(_what_, _var_) \
    _ACOW_PRIV_ACOW_FLAG_HAS(_what_, _var_)

#define ACOW_FLAG_HAS_ANY(_var_,  ...) \
    _ACOW_PRIV_ACOW_FLAG_HAS_ANY(_var_, __VA_ARGS__)

#define ACOW_FLAG_HAS_ALL(_var_, ...) \
    _ACOW_PRIV_ACOW_FLAG_HAS_ALL(_var_, __VA_ARGS__)


//----------------------------------------------------------------------------//
// Exclusivity                                                                //
//----------------------------------------------------------------------------//
#define ACOW_FLAG_ARE_EXCLUSIVE(_var_, ...) \
    _ACOW_PRIV_ACOW_FLAG_ARE_EXCLUSIVE(_var_,  __VA_ARGS__)
