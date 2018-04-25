#pragma once

//----------------------------------------------------------------------------//
// Export Headers                                                             //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// "Fake std"
#include "stdlib.h"
//------------------------------------------------------------------------------
// Assert
#include "include/Assert/assert.h"
//------------------------------------------------------------------------------
// Bitwise
#include "include/Bitwise/bitwise_utils.h"
//------------------------------------------------------------------------------
// Code
#include "include/Code/deprecated.h"
#include "include/Code/fake_keywords.h"
#include "include/Code/macros.h"
//------------------------------------------------------------------------------
// Debug
#include "include/Debug/debugger.h"
#include "include/Debug/not_implemented.h"
#include "include/Debug/only_in_debug.h"
//------------------------------------------------------------------------------
// Discovery
#include "include/Discovery/compiler_macros.h"
#include "include/Discovery/cpp_support.h"
#include "include/Discovery/processor_macros.h"
#include "include/Discovery/os_macros.h"
//------------------------------------------------------------------------------
// File
#include "include/File/file.h"
//------------------------------------------------------------------------------
// Memory
#include "include/Memory/memory.h"
//------------------------------------------------------------------------------
// Pointers
#include "include/Pointers/pointers.h"
//------------------------------------------------------------------------------
// String
#include "include/String/string.h"
//------------------------------------------------------------------------------
// Types
#include "include/Types/numeric_types.h"
#include "include/Types/time_types.h"
//------------------------------------------------------------------------------
// Version
#include "include/version.h"