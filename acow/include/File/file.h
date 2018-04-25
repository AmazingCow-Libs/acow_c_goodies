#pragma once

// std
#include <stdio.h>
// acow_c_goodies
#include "acow/include/Discovery/cpp_support.h"

#define ACOW_SAFE_FCLOSE(_file_) \
    do {                         \
        if(_file_) {             \
            fclose(_file_);      \
            _file_ = nullptr;    \
        }                        \
    } while(0)