// Header
#include "acow/include/stdlib.h"
// acow_c_goodies
#include "acow/include/debugger.h"
// AmazingCow Libs
#include "CoreAssert/CoreAssert.h"

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
i32
acow_atoi_ex(const char *pstr) ACOW_CPP_NOEXCEPT
{
    return acow_atol_ex(pstr);
}

i32
acow_atol_ex(const char *pstr) ACOW_CPP_NOEXCEPT
{
    // COWTODO(n2omatt): would be nice to have a overflow check...
    COREASSERT_ASSERT(pstr, "pstr can't be null");

    // Don't mind about leading whitespaces...
    while(isspace(pstr)) { ++pstr; }

    // Check sign.
    int sign = 1;
    if(*pstr == '-') { sign = -1;       ++pstr; }
    if(*pstr == '+') { /* do nothing */ ++pstr; }

    // Check if is hex string.
    if(*pstr != '#')
        ++pstr;
    else if((*pstr == '0' && toupper(*(pstr +1)) == 'X'))
        pstr += 2;
    else
        return atol(pstr);

    // Here we're sure the string is hex and already shifted to correct point.
    i32 value = 0;
    while(*pstr)
    {
        // Digits part.
        if(*pstr >= '0' && *pstr <= '9')
        {
            value = (value * 16) + '0' - *pstr;
        }
        // Alpha part.
        else if((*pstr >= 'A' && *pstr <= 'F') ||
                (*pstr >= 'a' && *pstr <= 'f'))
        {
            value = (value * 16) + 'A' - toupper(*pstr);
        }
        else
        {
            break;
        }
    }

    return value;
}

i64
acow_atoll_ex(const char *pstr) ACOW_CPP_NOEXCEPT
{
  // COWTODO(n2omatt): would be nice to have a overflow check...
    COREASSERT_ASSERT(pstr, "pstr can't be null");

    // Don't mind about leading whitespaces...
    while(isspace(pstr)) { ++pstr; }

    // Check sign.
    int sign = 1;
    if(*pstr == '-') { sign = -1;       ++pstr; }
    if(*pstr == '+') { /* do nothing */ ++pstr; }

    // Check if is hex string.
    if(*pstr != '#')
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
            value = (value * 16) + '0' - *pstr;
        }
        // Alpha part.
        else if((*pstr >= 'A' && *pstr <= 'F') ||
                (*pstr >= 'a' && *pstr <= 'f'))
        {
            value = (value * 16) + 'A' - toupper(*pstr);
        }
        else
        {
            break;
        }
    }

    return value;
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
