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
#include "acow/include/stdlib.h"
// std
#include <ctype.h>
// AmazingCow Libs
#include "CoreAssert/CoreAssert.h"
// acow_c_goodies
#include "acow/include/debugger.h"


//----------------------------------------------------------------------------//
// ato*                                                                       //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// C Functions.
#if (ACOW_C_GOODIES_USE_ACOW_ATOX_FUNCTIONS)

double
acow_atof(const char *pstr)
{
    COREASSERT_ASSERT(pstr, "pstr can't be null");
    return atof(pstr);
}

int
acow_atoi(const char *pstr)
{
    COREASSERT_ASSERT(pstr, "pstr can't be null");
    return atoi(pstr);
}

long int
acow_atol(const char *pstr)
{
    COREASSERT_ASSERT(pstr, "pstr can't be null");
    return atol(pstr);
}

long long int
acow_atoll(const char *pstr)
{
    COREASSERT_ASSERT(pstr, "pstr can't be null");
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
    COREASSERT_ASSERT(pstr, "pstr can't be null");

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
    COREASSERT_ASSERT(pstr, "pstr can't be null");

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
    COREASSERT_ASSERT(pname, "pname can't be null");
    return getenv(pname);
}

int
acow_putenv(const char *pstr)
{
    COREASSERT_ASSERT(pstr, "pstr can't be null");
    return putenv(pstr);
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
    COREASSERT_ASSERT(pcommand, "pcommand can't be null");
    return system(pcommand);
}

#endif
