//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : stdlib.h                                                      //
//  Project   : acow_c_goodies                                                //
//  Date      : Mar 10, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// std
#include <stdlib.h>
// acow_c_goodies
#include "numeric_types.h"
#include "cpp_support.h"

//----------------------------------------------------------------------------//
// ato*                                                                       //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// C Functions.
double        acow_atof (const char *pstr);
int           acow_atoi (const char *pstr);
long int      acow_atol (const char *pstr);
long long int acow_atoll(const char *pstr);

//------------------------------------------------------------------------------
// Amazing Cow Functions.
// @brief atoi with support for hexadecimal strings in format of: #hex, 0xhex.
int acow_atoi_ex(const char *pstr) ACOW_CPP_NOEXCEPT;

// @brief atol with support for hexadecimal strings in format of: #hex, 0xhex.
long acow_atol_ex(const char *pstr) ACOW_CPP_NOEXCEPT;

// @brief atoll with support for hexadecimal strings in format of: #hex, 0xhex.
long long acow_atoll_ex(const char *pstr) ACOW_CPP_NOEXCEPT;

//------------------------------------------------------------------------------
// Feature Macros.
#if !(ACOW_C_GOODIES_USE_ACOW_ATOX_FUNCTIONS)
    #define acow_atof  atof
    #define acow_atoi  atoi
    #define acow_atol  atol
    #define acow_atoll atoll
#endif



//----------------------------------------------------------------------------//
// abort                                                                      //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// C Functions.
void acow_abort(void);

//------------------------------------------------------------------------------
// Feature Macros.
#if !(ACOW_C_GOODIES_USE_ACOW_ABORT_FUNCTIONS)
    #define acow_abort abort
#endif



//----------------------------------------------------------------------------//
// get/set env                                                                //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// C Functions.
char* acow_getenv(const char *pname);
int   acow_putenv(const char *pstr);

//------------------------------------------------------------------------------
// Feature Macros.
#if !(ACOW_C_GOODIES_USE_ACOW_ABORT_FUNCTIONS)
    #define acow_getenv getenv
    #define acow_putenv putenv
#endif



//----------------------------------------------------------------------------//
// system                                                                     //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// C Functions.
int acow_system(const char *pcommand);

//------------------------------------------------------------------------------
// Feature Macros.
#if !(ACOW_C_GOODIES_USE_ACOW_SYSTEM_FUNCTIONS)
    #define acow_system system
#endif
