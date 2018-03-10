//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : OSMacros.h                                                    //
//  Project   : acow_c_goodies                                                //
//  Date      : Jan 22, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

//----------------------------------------------------------------------------//
// OSes                                                                       //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// BSDs
#if defined(   BSD         ) || \
    defined( __FreeBSD__   ) || \
    defined( __NetBSD__    ) || \
    defined( __OpenBSD__   ) || \
    defined( __bsdi__      ) || \
    defined( __DragonFly__ )

    #define ACOW_OS_IS_BSD 1
#else
    #define ACOW_OS_IS_BSD 0
#endif

//------------------------------------------------------------------------------
// Cygwin
#if defined( __CYGWIN__ )
    #define ACOW_OS_IS_CYGWIN 1
#else
    #define ACOW_OS_IS_CYGWIN 0
#endif

//------------------------------------------------------------------------------
// GNU/Linux
#if defined ( __gnu_linux__ ) ||  \
    defined ( __linux__     )

    #define ACOW_OS_IS_GNU_LINUX 1
#else
    #define ACOW_OS_IS_GNU_LINUX  0
#endif

//------------------------------------------------------------------------------
// OSX
#if defined( __APPLE__ ) && \
    defined( __MACH__  )

    #define ACOW_OS_IS_OSX 1
#else
    #define ACOW_OS_IS_OSX 0
#endif

//------------------------------------------------------------------------------
// Windows
#if defined( _WIN32 )

    #define ACOW_OS_IS_WINDOWS 1
#else
    #define ACOW_OS_IS_WINDOWS 0
#endif

//------------------------------------------------------------------------------
// UNIX
#if ACOW_OS_IS_BSD       || \
    ACOW_OS_IS_CYGWIN    || \
    ACOW_OS_IS_GNU_LINUX || \
    ACOW_OS_IS_OSX

    #define ACOW_OS_IS_UNIX 1
#else
    #define ACOW_OS_IS_UNIX 0
#endif
