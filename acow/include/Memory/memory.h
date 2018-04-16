//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Memory.h                                                      //
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

// acow_c_goodies
#include "acow/include/Discovery/cpp_support.h"
#include "acow/include/Types/numeric_types.h"


//----------------------------------------------------------------------------//
// *alloc                                                                     //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// C Functions.
void* acow_alloca(size_t size);
void* acow_malloc(size_t size);

void acow_free(void *ptr);

//------------------------------------------------------------------------------
// Feature Macros
#if !(ACOW_C_GOODIES_USE_ACOW_MEMORY_FUNCTIONS)
    #define acow_alloca alloca
    #define acow_malloc malloc
    #define acow_free   free
#endif

// COWTODO(n2omatt): Implement....
// extern void *calloc  (size_t __nmemb, size_t __size)
// extern void *realloc (void *__ptr, size_t __size)

//----------------------------------------------------------------------------//
// Goodies Macros                                                             //
//----------------------------------------------------------------------------//
#define ACOW_SIZE_BYTES(_size_) _size_
#define ACOW_SIZE_KBYTES(_size_) ACOW_SIZE_BYTES((_size_))  * 1024
#define ACOW_SIZE_MBYTES(_size_) ACOW_SIZE_KBYTES((_size_)) * 1024
#define ACOW_SIZE_GBYTES(_size_) ACOW_SIZE_MBYTES((_size_)) * 1024

#define ACOW_SIZEOF(_type_, _count_) ( sizeof(_type_) * (_count_) )

#define ACOW_SAFE_FREE(_ptr_)   \
    do {                        \
        if((_ptr_)) {           \
            acow_free((_ptr_)); \
            (_ptr_) = nullptr;  \
        }                       \
    } while(0)
