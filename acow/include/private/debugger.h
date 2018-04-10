#pragma once

// acow_c_goodies
#include "acow/include/os_macros.h"

#if (ACOW_OS_IS_LINUX) 
    #define _ACOW_PRIV_ACOW_DEBUGGER_BREAK() \
        do {                                 \
             if(acow_is_debugger_present()){ \
                 __asm__("int3");            \
             }                               \
         } while(0)
#elif (ACOW_OS_IS_WINDOWS)
    #define WINDOWS_LEAN_AND_MEAN   
    #define _WINSOCKAPI_    
    #include <Windows.h>

    #define _ACOW_PRIV_ACOW_DEBUGGER_BREAK() \
        DebugBreak()    
#else 
    #error "DEBUGGER_BREAK IS NOT DEFINED FOR THIS OS"
#endif