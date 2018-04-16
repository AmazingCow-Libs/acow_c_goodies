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
#include "acow/include/Discovery/cpp_support.h"
#include "acow/include/Types/numeric_types.h"


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
#ifdef _MSC_VER // Microsoft compilers

    #define _ACOW_PRIV_VA_NARGS(...)  INTERNAL_EXPAND_ARGS_PRIVATE(INTERNAL_ARGS_AUGMENTER(__VA_ARGS__))

    #define INTERNAL_ARGS_AUGMENTER(...) unused, __VA_ARGS__
    #define INTERNAL_EXPAND(x) x
    #define INTERNAL_EXPAND_ARGS_PRIVATE(...) INTERNAL_EXPAND(INTERNAL_GET_ARG_COUNT_PRIVATE(__VA_ARGS__, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))
    #define INTERNAL_GET_ARG_COUNT_PRIVATE(_1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, _9_, _10_, _11_, _12_, _13_, _14_, _15_, _16_, _17_, _18_, _19_, _20_, _21_, _22_, _23_, _24_, _25_, _26_, _27_, _28_, _29_, _30_, _31_, _32_, _33_, _34_, _35_, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, count, ...) count

#else // Non-Microsoft compilers

    #define _ACOW_PRIV_VA_NARGS(...) INTERNAL_GET_ARG_COUNT_PRIVATE(0, ## __VA_ARGS__, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
    #define INTERNAL_GET_ARG_COUNT_PRIVATE(_0, _1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, _9_, _10_, _11_, _12_, _13_, _14_, _15_, _16_, _17_, _18_, _19_, _20_, _21_, _22_, _23_, _24_, _25_, _26_, _27_, _28_, _29_, _30_, _31_, _32_, _33_, _34_, _35_, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, count, ...) count

#endif


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
    (((_var_) & (_what_)) == (_what_))

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
