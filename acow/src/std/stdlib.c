//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : stdlib.c                                                      //
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
#include "acow/include/std/stdlib.h"
// std
#include <stdlib.h>
#include <ctype.h>
// acow_c_goodies
#include "acow/include/Assert/assert.h"
#include "acow/include/Debug/debugger.h"


//----------------------------------------------------------------------------//
// ato*                                                                       //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// C Functions.
#if (ACOW_C_GOODIES_USE_ACOW_ATOX_FUNCTIONS)

double
acow_atof(const char *pstr)
{
    ACOW_ASSERT_NOT_NULL(pstr);
    return atof(pstr);
}

int
acow_atoi(const char *pstr)
{
    ACOW_ASSERT_NOT_NULL(pstr);
    return atoi(pstr);
}

long int
acow_atol(const char *pstr)
{
    ACOW_ASSERT_NOT_NULL(pstr);
    return atol(pstr);
}

long long int
acow_atoll(const char *pstr)
{
    ACOW_ASSERT_NOT_NULL(pstr);
    return atoll(pstr);
}

#endif // (ACOW_C_GOODIES_USE_ACOW_ATOX_FUNCTIONS)

//------------------------------------------------------------------------------
// Amazing Cow Functions.
int
acow_atoi_ex(const char *pstr) ACOW_CPP_NOEXCEPT
{
    return acow_atol_ex(pstr);
}

long
acow_atol_ex(const char *pstr) ACOW_CPP_NOEXCEPT
{
   // COWTODO(n2omatt): would be nice to have a overflow check...
    ACOW_ASSERT_NOT_NULL(pstr);

    // Don't mind about leading whitespaces...
    while(isspace(*pstr)) { ++pstr; }

    // Check sign.
    int sign = 1;
    if(*pstr == '-') { sign = -1;       ++pstr; }
    if(*pstr == '+') { /* do nothing */ ++pstr; }

    // Check if is hex string.
    if(*pstr == '#')
        ++pstr;
    else if((*pstr == '0' && toupper(*(pstr +1)) == 'X'))
        pstr += 2;
    else
        return atol(pstr);

    // Here we're sure the string is hex and already shifted to correct point.
    i64 value = 0;
    while(*pstr)
    {
        // Digits part.
        if(*pstr >= '0' && *pstr <= '9')
        {
            value = (value * 16) + (*pstr - '0');
        }
        // Alpha part.
        else if((*pstr >= 'A' && *pstr <= 'F') ||
                (*pstr >= 'a' && *pstr <= 'f'))
        {
            value = (value * 16) + (toupper(*pstr) - 'A' + 10);
        }
        else
        {
            break;
        }

        ++pstr;
    }

    return value * sign;
}

long long
acow_atoll_ex(const char *pstr) ACOW_CPP_NOEXCEPT
{
    // COWTODO(n2omatt): would be nice to have a overflow check...
    ACOW_ASSERT_NOT_NULL(pstr);

    // Don't mind about leading whitespaces...
    while(isspace(*pstr)) { ++pstr; }

    // Check sign.
    int sign = 1;
    if(*pstr == '-') { sign = -1;       ++pstr; }
    if(*pstr == '+') { /* do nothing */ ++pstr; }

    // Check if is hex string.
    if(*pstr == '#')
        ++pstr;
    else if((*pstr == '0' && toupper(*(pstr +1)) == 'X'))
        pstr += 2;
    else
        return atoll(pstr);

    // Here we're sure the string is hex and already shifted to correct point.
    i64 value = 0;
    while(*pstr)
    {
        // Digits part.
        if(*pstr >= '0' && *pstr <= '9')
        {
            value = (value * 16) + (*pstr - '0');
        }
        // Alpha part.
        else if((*pstr >= 'A' && *pstr <= 'F') ||
                (*pstr >= 'a' && *pstr <= 'f'))
        {
            value = (value * 16) + (toupper(*pstr) - 'A' + 10);
        }
        else
        {
            break;
        }

        ++pstr;
    }

    return value * sign;
}


//----------------------------------------------------------------------------//
// abort                                                                      //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// C Functions.
#if (ACOW_C_GOODIES_USE_ACOW_ABORT_FUNCTIONS)

void
acow_abort(void)
{
    ACOW_DEBUGGER_BREAK();
    abort();
}

#endif //(ACOW_C_GOODIES_USE_ACOW_ABORT_FUNCTIONS)


//----------------------------------------------------------------------------//
// get/set env                                                                //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// C Functions.
#if (ACOW_C_GOODIES_USE_ACOW_ABORT_FUNCTIONS)

char*
acow_getenv(const char *pname)
{
    // COWNOTE: On MSVC without CRT_SECURE_NO_WARNINGS this emits a warning.
    ACOW_ASSERT_NOT_NULL(pname);
    return getenv(pname); 
}

int
acow_putenv(const char *pstr)
{
    // COWNOTE: On MSVC without CRT_SECURE_NO_WARNINGS this emits a warning.
    ACOW_ASSERT_NOT_NULL(pstr);
    return putenv((char*)pstr);
}

#endif // (ACOW_C_GOODIES_USE_ACOW_ABORT_FUNCTIONS)



//----------------------------------------------------------------------------//
// system                                                                     //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// C Functions.
#if (ACOW_C_GOODIES_USE_ACOW_SYSTEM_FUNCTIONS)
int
acow_system(const char *pcommand)
{
    ACOW_ASSERT_NOT_NULL(pcommand);
    return system(pcommand);
}

#endif
