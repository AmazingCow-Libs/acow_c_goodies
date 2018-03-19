#pragma once

#include "cpp_support.h"
#include "numeric_types.h"

#define ACOW_ENUM_TO_INT(_enum_value_) (i32)(_enum_value_)

#define ACOW_SCOPE(_name_)

// Trick grabbed from:
//   https://stackoverflow.com/q/9185429
#if (ACOW_IS_CPP)
    #define ACOW_DEFAULT_VALUE(_val_) = _val_
#else
    #define ACOW_DEFAULT_VALUE(_val_)
#endif
