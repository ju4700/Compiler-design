#include "codegen.h"

// This file is intentionally minimal as the CodeGenerator class
// is defined entirely in the header file (codegen.h) for simplicity.
// The print_bangla function is now generated as LLVM IR at runtime
// to properly handle dynamic integer-to-Bangla conversion.