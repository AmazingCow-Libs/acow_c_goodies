//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : memory.c                                                      //
//  Project   : acow_c_goodies                                                //
//  Date      : Mar 10, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// Header
#include "acow/include/Memory/memory.h"
// std
#include <stdlib.h>
#include <string.h>
// acow_c_goodies
#include "acow/include/Assert/assert.h"
#include "acow/include/Code/fake_keywords.h"
#include "acow/include/Discovery/cpp_support.h"
#include "acow/include/Discovery/os_macros.h"

#if (ACOW_OS_IS_WINDOWS)
    #include <malloc.h>
#endif

//----------------------------------------------------------------------------//
// Helper Functions                                                           //
//----------------------------------------------------------------------------//
acow_internal_function inline void
_acow_reset_memory(void *pMemory, size_t size, u8 what) ACOW_CPP_NOEXCEPT
{
    memset(pMemory, what, size);
}

#if (ACOW_C_GOODIES_USE_ACOW_MEMORY_CLEAN)
    #define acow_reset_memory(_mem_, _sz_, _i_) _acow_reset_memory(_mem_, _sz_, _i_)
#else
    #define acow_reset_memory(_mem_, _sz_, _i_) do { /* no-op */ } while(0)
#endif

#define ACOW_C_GOODIES_MEMORY_CLEAN_BYTE 0


//----------------------------------------------------------------------------//
// *alloc                                                                     //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// C Functions.
#if (ACOW_C_GOODIES_USE_ACOW_MEMORY_FUNCTIONS)

void*
acow_alloca(size_t size)
{
    // COWTODO(n2omatt): A way to get the stack size would be nice...
    void* p_memory = alloca(size);

    ACOW_ASSERT(p_memory, "Can't alloca(3) memory - Size: %d", size);
    acow_reset_memory(p_memory, size, ACOW_C_GOODIES_MEMORY_CLEAN_BYTE);

    return p_memory;
}

void*
acow_malloc(size_t size)
{
    // COWTODO(n2omatt): Size 0??? how to handle?

    void* p_memory = malloc(size);

    ACOW_ASSERT(p_memory, "Can't malloc(3) memory - Size: %d", size);
    acow_reset_memory(p_memory, size, ACOW_C_GOODIES_MEMORY_CLEAN_BYTE);

    return p_memory;
}

void
acow_free(void *ptr)
{
    // COWTODO(n2omatt): any checks??
    free(ptr);
}

#endif // (ACOW_C_GOODIES_USE_ACOW_MEMORY_FUNCTIONS)
