#pragma once

// std
#include "stdarg.h"
// acow_c_goodies
#include "acow/include/Discovery/cpp_support.h"
#include "acow/include/Types/numeric_types.h"


//------------------------------------------------------------------------------
// C Functions.
void* acow_memcpy(void *dst, void *src, size_t size) ACOW_CPP_NOEXCEPT;

//------------------------------------------------------------------------------
// Feature Macros
#if !(ACOW_C_GOODIES_USE_ACOW_STRING_FUNCTIONS)
    #define acow_memcpy memcpy
#endif


//------------------------------------------------------------------------------
// AmazingCow Functions.
char* acow_string_static_small_format(
    const char *pFormat, ...) ACOW_CPP_NOEXCEPT;

char* acow_string_format(const char* pFormat, ...) ACOW_CPP_NOEXCEPT;

char* acow_string_format_va(
    const char *pFormat,
    va_list     list_args) ACOW_CPP_NOEXCEPT;

u32 acow_string_format_va_needed_size(
    const char *pFormat,
    va_list     list_args) ACOW_CPP_NOEXCEPT;


bool acow_string_equals(
    const char *pStr1,
    const char *pStr2) ACOW_CPP_NOEXCEPT;


bool acow_string_empty              (const char *pStr1) ACOW_CPP_NOEXCEPT;
bool acow_string_empty_or_whitespace(const char *pStr1) ACOW_CPP_NOEXCEPT;

char* acow_string_alloc_copy(const char *pStr) ACOW_CPP_NOEXCEPT;


//------------------------------------------------------------------------------
// Goodies Macros
