//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : CompilerMacros.h                                              //
//  Project   : acow_c_goodies                                                //
//  Date      : Jan 25, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// Reference:
//   https://sourceforge.net/p/predef/wiki/Compilers/

//----------------------------------------------------------------------------//
// Clang                                                                      //
//----------------------------------------------------------------------------//
#if defined(__clang__)
    #define ACOW_COMPILER_CLANG 1
#else
    #define ACOW_COMPILER_CLANG 0
#endif


//----------------------------------------------------------------------------//
// GCC                                                                        //
//----------------------------------------------------------------------------//
#if defined(__GNUC__)
    #define ACOW_COMPILER_GCC 1
#else
    #define ACOW_COMPILER_GCC 0
#endif


//----------------------------------------------------------------------------//
// Microsoft Visual C++                                                       //
//----------------------------------------------------------------------------//
#if defined(_MSC_VER)
    #define ACOW_COMPILER_MSVC 1
#else
    #define ACOW_COMPILER_MSVC 0
#endif