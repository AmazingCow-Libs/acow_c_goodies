//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : FakeKeywords.h                                                //
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

//----------------------------------------------------------------------------//
// static                                                                     //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// We share the Casey Muratori's view on how ambiguous the static keyword are
// in C/C++ as he presented on the "Handmade Hero Day 003", so we decided
// to borrow his ideas on how make it nicer,
//
// BTW, the Handmade Hero series are really nice, you should check out ;D
//   Reference: https://www.youtube.com/watch?v=GAi_nTx1zG8
//
// Thanks Casey...
//

///-----------------------------------------------------------------------------
/// @brief
///   Functions that should be meaningful in only one translation unit.
/// @example
///  acow_internal_function void some_helper(int param) noexcept;
#define acow_internal_function static

///-----------------------------------------------------------------------------
/// @brief
///   Variables that should be initialized only once and retains its value
///   after subsequent scope changes.
/// @example
///   acow_local_persist auto some_var = 10;
#define acow_local_persist static

///-----------------------------------------------------------------------------
/// @brief
///   Variables that should be used in only one tranlation unit.
/// @example
///   acow_global_variable int g_some_var;
#define acow_global_variable static