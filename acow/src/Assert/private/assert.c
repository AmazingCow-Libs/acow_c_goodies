//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : PrivateHelpers.cpp                                            //
//  Project   : CoreAssert                                                    //
//  Date      : Dec 14, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// Header
#include "acow/include/Assert/private/assert.h"
// std
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
// acow_c_goodies
#include "acow/include/Code/fake_keywords.h"
#include "acow/include/Memory/memory.h"


///----------------------------------------------------------------------------//
/// Constants                                                                  //
///----------------------------------------------------------------------------//
#define MAX_BUFFER_SIZE 2048


///----------------------------------------------------------------------------//
/// Helper Functions                                                           //
///----------------------------------------------------------------------------//
acow_internal_function void
vformat(
    char       *pBuffer,
    size_t      bufferSize,
    const char *pFormat,
    va_list     list) ACOW_CPP_NOEXCEPT
{
    memset(pBuffer, bufferSize, 0);

    // Build the buffer with the variadic args list.
    vsnprintf(pBuffer, bufferSize, pFormat, list);

    return;
}

acow_internal_function void
PrintMessageAndAbort(char *pMessage) ACOW_CPP_NOEXCEPT
{
    fprintf(stderr, pMessage);
    fflush (stderr);

    abort();
}


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
ACOW_EXTERN_C void
_acow_assert_private_print_assertion_and_abort(
    const    char *pExpressionStr,
    const    char *pFileStr,
    unsigned int   line,
    const    char *pFunctionStr,
    const    char *pDetailMessageFmt,
    ...) ACOW_CPP_NOEXCEPT
{
    //--------------------------------------------------------------------------
    // Notes:
    //  p_detail_msg_buffer and p_assertion_msg_buffer allocated bellow
    //  will leak since we're not freeing them, but that doesn't matters here
    //  since the whole application will shutdown anyways.

    //--------------------------------------------------------------------------
    // Build the Detail Message.
    va_list args;
    va_start(args, pDetailMessageFmt);
        u32   detail_msg_buffer_size = ACOW_SIZEOF(char, MAX_BUFFER_SIZE);
        char *p_detail_msg_buffer    = (char *)malloc(detail_msg_buffer_size);

        vformat(
            p_detail_msg_buffer,
            detail_msg_buffer_size,
            pDetailMessageFmt,
            args
        );

        detail_msg_buffer_size = strlen(p_detail_msg_buffer);
    va_end(args);


    //--------------------------------------------------------------------------
    // Build the Assertion Messsage.
    acow_local_persist const char *kAssertionMessage_Fmt =
 "Assert: assertion failed on: \n \
  file       : %s \n \
  line       : %d \n \
  function   : %s \n \
  expression : %s \n \
  message    : %s \n";

    char *p_assertion_msg_buffer = (char *)malloc(
        ACOW_SIZEOF(char, MAX_BUFFER_SIZE + detail_msg_buffer_size)
    );    
    sprintf(
        p_assertion_msg_buffer,
        kAssertionMessage_Fmt,
        pFileStr,
        line,
        pFunctionStr,
        pExpressionStr,
        p_detail_msg_buffer
     );

    //--------------------------------------------------------------------------
    // Print the message and abort.
    PrintMessageAndAbort(p_assertion_msg_buffer);
}

//------------------------------------------------------------------------------
ACOW_EXTERN_C void
_acow_assert_private_print_unreachable_and_abort(
    const    char *pFileStr,
    unsigned int   line,
    const    char *pFunctionStr,
    const    char *pDetailMessageFmt,
    ...) ACOW_CPP_NOEXCEPT
{
    //--------------------------------------------------------------------------
    // Notes:
    //  p_detail_msg_buffer and p_assertion_msg_buffer allocated bellow
    //  will leak since we're not freeing them, but that doesn't matters here
    //  since the whole application will shutdown anyways.

    //--------------------------------------------------------------------------
    // Build the Detail Message.
    va_list args;
    va_start(args, pDetailMessageFmt);
        u32   detail_msg_buffer_size = ACOW_SIZEOF(char, MAX_BUFFER_SIZE);
        char *p_detail_msg_buffer    = (char *)malloc(detail_msg_buffer_size);

        vformat(
            p_detail_msg_buffer,
            detail_msg_buffer_size,
            pDetailMessageFmt,
            args
        );

        detail_msg_buffer_size = strlen(p_detail_msg_buffer);
    va_end(args);


    //--------------------------------------------------------------------------
    // Build the Final Messsage.
    acow_local_persist const char *kFinalMessage_Fmt =
 "Assert: Unreachable code found on: \n \
  file       : %s \n \
  line       : %d \n \
  function   : %s \n \
  details    : %s \n";

    char *p_final_msg_buffer = (char *)malloc(
        ACOW_SIZEOF(char, MAX_BUFFER_SIZE + detail_msg_buffer_size)
    );
    sprintf(
        p_final_msg_buffer,
        kFinalMessage_Fmt,
        pFileStr,
        line,
        pFunctionStr,
        p_detail_msg_buffer
     );

    //--------------------------------------------------------------------------
    // Print the message and abort.
    PrintMessageAndAbort(p_final_msg_buffer);
}
