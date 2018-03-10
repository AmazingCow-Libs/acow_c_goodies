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
// acow_c_utils
#include "../numeric_types.h"
#include "../cpp_support.h"


//----------------------------------------------------------------------------//
//                                                                            //
// Private Function Declarations                                              //
//                                                                            //
//----------------------------------------------------------------------------//
bool _acow_private_flag_check_has_any    (u32 var, u8 argsSize, ...) ACOW_CPP_NOEXCEPT;
bool _acow_private_flag_check_has_all    (u32 var, u8 argsSize, ...) ACOW_CPP_NOEXCEPT;
bool _acow_private_flag_check_exclusivity(u32 var, u8 argsSize, ...) ACOW_CPP_NOEXCEPT;


//----------------------------------------------------------------------------//
//                                                                            //
// MACROS                                                                     //
//                                                                            //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// Count the number of arguments on variadic list.
//   thanks to: aprell (https://gist.github.com/aprell/3722962)
#define _ACOW_PRIV_VA_NARGS_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) \
    N
#define _ACOW_PRIV_VA_NARGS(...) \
    _ACOW_PRIV_VA_NARGS_IMPL(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)


//----------------------------------------------------------------------------//
// Add / Remove                                                               //
//----------------------------------------------------------------------------//
#define _ACOW_PRIV_ACOW_FLAG_ADD(_what_, _var_) \
    ((_var_) |= (_what_))

#define _ACOW_PRIV_ACOW_FLAG_REMOVE(_what_, _var_)


//----------------------------------------------------------------------------//
// Has                                                                        //
//----------------------------------------------------------------------------//
#define _ACOW_PRIV_ACOW_FLAG_HAS(_what_, _var_) \
    ((_var_) & (_what_))

#define _ACOW_PRIV_ACOW_FLAG_HAS_ANY(_var_, ...) \
    _acow_private_flag_check_has_any(            \
            (_var_),                             \
            _ACOW_PRIV_VA_NARGS(__VA_ARGS__),    \
            __VA_ARGS__                          \
    )

#define _ACOW_PRIV_ACOW_FLAG_HAS_ALL(_var_, ...) \
    _acow_private_flag_check_has_all(            \
            (_var_),                             \
            _ACOW_PRIV_VA_NARGS(__VA_ARGS__),    \
            __VA_ARGS__                          \
    )


//----------------------------------------------------------------------------//
// Exclusivity                                                                //
//----------------------------------------------------------------------------//
#define _ACOW_PRIV_ACOW_FLAG_ARE_EXCLUSIVE(_var_, ...) \
    _acow_private_flag_check_exclusivity(              \
        (_var_),                                       \
        _ACOW_PRIV_VA_NARGS(__VA_ARGS__),              \
         __VA_ARGS__                                   \
    )
