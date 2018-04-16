//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : numeric_types.h                                               //
//  Project   : acow_c_goodies                                                //
//  Date      : Mar 09, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// std
#include <stdint.h>
#include <stddef.h>
// acow_c_goodies
#include "acow/include/Discovery/cpp_support.h"


//----------------------------------------------------------------------------//
// Integer                                                                    //
//----------------------------------------------------------------------------//
typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef uint8_t byte;

//----------------------------------------------------------------------------//
// Bool                                                                       //
//----------------------------------------------------------------------------//
#if !(ACOW_IS_CPP)
    #include <stdbool.h>
    #define nullptr NULL
#endif

//----------------------------------------------------------------------------//
// Float                                                                      //
//----------------------------------------------------------------------------//
typedef float  f32;
typedef double f64;