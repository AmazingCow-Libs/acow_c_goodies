
// AmazingCow Libs
#include "CoreAssert/CoreAssert.h"
// acow_c_goodies
#include "macros.h"
#include "string.h"


#define ACOW_ASSERT_NOT_NULL(_pointer_) \
    COREASSERT_ASSERT_NOT_NULL(_pointer_)

#define ACOW_ASSERT_STR_NOT_EMPTY(_str_)                \
    COREASSERT_ASSERT(                                  \
        !acow_string_empty(_str_),                      \
        "Var: " ACOW_STRINGIZE(_str_) " can't be empty" \
    )

#define ACOW_ASSERT_NOT_STR_EMPTY_OR_WHITESPACE(_str_)                \
    COREASSERT_ASSERT(                                                \
        !acow_string_empty_or_whitespace(_str_),                      \
        "Var: " ACOW_STRINGIZE(_str_) " can't be empty or whitespace" \
    )
