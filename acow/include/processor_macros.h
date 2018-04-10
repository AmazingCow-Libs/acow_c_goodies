//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : ProcessorMacros.h                                             //
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

//----------------------------------------------------------------------------//
// Processor                                                                  //
//----------------------------------------------------------------------------//

// COWTODO(n2omatt): Add other processor archs...
#if (_WIN64)  || (__x86_64__) || (__ppc64__)
    #define ACOW_PROCESSOR_32BIT 0
    #define ACOW_PROCESSOR_64BIT 1
#else
    #define ACOW_PROCESSOR_32BIT 1
    #define ACOW_PROCESSOR_64BIT 0
#endif


//COWTODO(n2omatt): Implelement for other processors family.
//x86 family
//  Taken from: http://nadeausoftware.com/articles/2012/02/c_c_tip_how_detect_processor_type_using_compiler_predefined_macros
#if defined(i386) || defined(__i386) || defined(__i386__) || defined(_M_IX86) || defined(_X86_)
    #define ACOW_PROCESSOR_INTELX86  1
    #define ACOW_PROCESSOR_INTELIA64 0
    #define ACOW_PROCESSOR_ARM       0
#endif

//amd64 family
//  Taken from: http://nadeausoftware.com/articles/2012/02/c_c_tip_how_detect_processor_type_using_compiler_predefined_macros
#if __x86_64 || __x86_64__ || __amd64 || __amd64__ || _M_AMD64 || _M_X64
    #define ACOW_PROCESSOR_INTELX86  1
    #define ACOW_PROCESSOR_INTELIA64 0
    #define ACOW_PROCESSOR_ARM       0
#endif
