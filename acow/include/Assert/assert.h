//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Assert.h                                                      //
//  Project   : CoreAssert                                                    //
//  Date      : Dec 14, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//    Provides a better assetion model than the standard assert macro         //
//    by the libc.                                                            //
//                                                                            //
//    The Asserts will have information of:                                   //
//      1 - The condition (the actual text) that failed.                      //
//      2 - The file path.                                                    //
//      3 - The line number.                                                  //
//      4 - The function the ASSERT is.                                       //
//      5 - A user given message with variadic arguments like printf(3)       //
//---------------------------------------------------------------------------~//

// acow_c_goodies
#include "acow/include/Code/macros.h"
#include "acow/include/String/string.h"
// acow_c_goodies - Private
#include "private/assert.h"


//----------------------------------------------------------------------------//
// Macros that depends on the preprocessor defines.                           //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// Assertions are enabled.
#if (ACOW_C_GOODIES_ENABLE_ASSERTS) 
    //COWTODO(n2omatt): Update docs...
    ///-------------------------------------------------------------------------
    /// @brief
    ///   Provides an runtime assertion about the condition.
    /// @param cond
    ///   The condition that will be tested - like (pFile != nullptr),
    ///   if the condition fails, the assertion will be triggered.
    /// @param msg
    ///   A C-style string message - It can contains the same format specifiers
    ///   as the printf(3) would accept.
    /// @param ...
    ///   Variadic arguments that will be used as argument to the format msg.
    /// @see
    ///   COREASSERT_VERIFY.
    #define ACOW_ASSERT(_cond_, _msg_, ...)  \
        ((_cond_))                           \
         ? (void) 0 /* No-Op */              \
         : _acow_assert_private_print_args(  \
                #_cond_,                     \
                __FILE__,                    \
                __LINE__,                    \
                __func__,                    \
                (_msg_),                     \
                ##__VA_ARGS__                \
           )

//------------------------------------------------------------------------------
// Assertions are disabled.
#else 
    #define ACOW_ASSERT(_cond_, _msg_, ...) \
        do { } while(0)

#endif // (ACOW_C_GOODIES_ENABLE_ASSERTS)


//----------------------------------------------------------------------------//
// Macros that depends only on other macros.                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
//COWTODO(n2omatt): Add docs.
#define ACOW_ASSERT_NOT_NULL(_var_)                    \
    ACOW_ASSERT(                                       \
        _var_ != nullptr,                              \
         "Var: " ACOW_STRINGIZE(_var_) "can't be null" \
    )

//------------------------------------------------------------------------------
//COWTODO(n2omatt): Add docs.
#define ACOW_ASSERT_CSTR_NOT_EMPTY(_str_)               \
    ACOW_ASSERT(                                        \
        !acow_string_empty(_str_),                      \
        "Var: " ACOW_STRINGIZE(_str_) " can't be empty" \
    )

//------------------------------------------------------------------------------
//COWTODO(n2omatt): Add docs.
#define ACOW_ASSERT_NOT_CSTR_EMPTY_OR_WHITESPACE(_str_)               \
    ACOW_ASSERT(                                                      \
        !acow_string_empty_or_whitespace(_str_),                      \
        "Var: " ACOW_STRINGIZE(_str_) " can't be empty or whitespace" \
    )