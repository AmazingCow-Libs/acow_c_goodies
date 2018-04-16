// Header
#include "acow/include/String/string.h"
// std
#include <stdio.h>
#include <ctype.h>
// acow_c_goodies
#include "acow/include/Assert/assert.h"
#include "acow/include/Code/fake_keywords.h"
#include "acow/include/Memory/memory.h"



//----------------------------------------------------------------------------//
// Constants                                                                  //
//----------------------------------------------------------------------------//
#define STRING_STATIC_SMALL_FORMAT 1024


//------------------------------------------------------------------------------
// AmazingCow Functions.
char*
acow_string_static_small_format(
    const char *pFormat, ...) ACOW_CPP_NOEXCEPT
{
    ACOW_ASSERT_NOT_NULL(pFormat);

    acow_local_persist char s_buffer[STRING_STATIC_SMALL_FORMAT] = {0};

    va_list _list;
    va_start(_list, pFormat);
        u32 written = vsnprintf(
            s_buffer,
            STRING_STATIC_SMALL_FORMAT,
            pFormat,
            _list
        );
        ACOW_ASSERT(written == 0, "Can't format string in small static.");
    va_end(_list);

    return s_buffer;
}

char*
acow_string_format(const char* pFormat, ...) ACOW_CPP_NOEXCEPT
{
    ACOW_ASSERT_NOT_NULL(pFormat);

    va_list _list;
    va_start(_list, pFormat);
        char *p_str =  acow_string_format_va(pFormat, _list);
    va_end(_list);

    return p_str;
}

char*
acow_string_format_va(
    const char *pFormat,
    va_list     list_args) ACOW_CPP_NOEXCEPT
{
    ACOW_ASSERT_NOT_NULL(pFormat);

    u32   required_size = acow_string_format_va_needed_size(pFormat, list_args);
    char *p_buf         = (char *)acow_malloc(ACOW_SIZEOF(char, required_size));
    u32   written_size  = vsnprintf(p_buf, required_size, pFormat, list_args);

    ACOW_ASSERT(
        (required_size -1) == written_size,
        "vsnprintf error - Required (%d) - Written (%d)",
        required_size,
        written_size
    );

    return p_buf;
}


u32
acow_string_format_va_needed_size(
    const char *pFormat,
    va_list     list_args) ACOW_CPP_NOEXCEPT
{
    ACOW_ASSERT_NOT_NULL(pFormat);

    va_list query_list;
    va_copy(query_list, list_args);
        u32 required_size = vsnprintf(nullptr, 0, pFormat, query_list);
    va_end(query_list);

    return ++required_size; // +1 for null terminator.
}


bool
acow_string_equals(
    const char *pStr1,
    const char *pStr2) ACOW_CPP_NOEXCEPT
{
    ACOW_ASSERT_NOT_NULL(pStr1);
    ACOW_ASSERT_NOT_NULL(pStr2);

    return (strcmp(pStr1, pStr2) == 0);
}

bool
acow_string_empty(const char *pStr1) ACOW_CPP_NOEXCEPT
{
    ACOW_ASSERT_NOT_NULL(pStr1);
    return (strlen(pStr1) == 0);
}

bool
acow_string_empty_or_whitespace(const char *pStr1) ACOW_CPP_NOEXCEPT
{
    if(acow_string_empty(pStr1))
        return true;

    while(*pStr1)
    {
        if(!isspace(*pStr1))
            return false;
    }

    return true;
}

char*
acow_string_alloc_copy(const char *pStr) ACOW_CPP_NOEXCEPT
{
    ACOW_ASSERT_NOT_NULL(pStr);

    u32   len   = strlen(pStr);
    char *p_dst = (char *)acow_malloc(ACOW_SIZEOF(char, len));

    return strcpy(p_dst, pStr);
}
