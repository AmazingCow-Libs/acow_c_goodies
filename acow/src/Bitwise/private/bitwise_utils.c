//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : bitwise_utils.c                                               //
//  Project   : acow_c_goodies                                                //
//  Date      : Feb 23, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// Header
#include "acow/include/Bitwise/private/bitwise_utils.h"
// std
#include <stdarg.h>
// acow_c_goodies
#include "acow/include/Types/numeric_types.h"


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
bool
_acow_private_flag_check_has_any(u32 var, u8 argsSize, ...) ACOW_CPP_NOEXCEPT
{
    va_list _list;
    va_start(_list, argsSize);

    while(argsSize--)
    {
        u32 curr_val = va_arg(_list, u32);
        if(_ACOW_PRIV_ACOW_FLAG_HAS(curr_val, var) != 0)
            return true;
    }
    va_end(_list);

    return false;
}

bool
_acow_private_flag_check_has_all(u32 var, u8 argsSize, ...) ACOW_CPP_NOEXCEPT
{
    va_list _list;
    va_start(_list, argsSize);

    while(argsSize--)
    {
        u32 curr_val = va_arg(_list, u32);
        if(_ACOW_PRIV_ACOW_FLAG_HAS(curr_val, var) == 0)
            return false;
    }
    va_end(_list);

    return true;
}

bool
_acow_private_flag_check_exclusivity(u32 var, u8 argsSize, ...) ACOW_CPP_NOEXCEPT
{
    va_list _list;
    va_start(_list, argsSize);

    u32 first_val = va_arg(_list, u32); argsSize--;
    bool result   = (_ACOW_PRIV_ACOW_FLAG_HAS(first_val, var) != 0);

    while(argsSize--)
    {
        u32 curr_val = va_arg(_list, u32);
        result ^= (_ACOW_PRIV_ACOW_FLAG_HAS(curr_val, var) != 0);
    }
    va_end(_list);

    return result;
}
