#include "codegen.h"

// Definition of int_to_bangla
std::string int_to_bangla(int value) {
    const char* bangla_digits = "০১২৩৪৫৬৭৮৯";  // UTF-8 encoded Bangla digits 0-9
    std::string result;
    if (value == 0) {
        result = std::string(bangla_digits, 3);  // "০" (3 bytes)
        return result;
    }
    while (value > 0) {
        int digit = value % 10;
        result = std::string(bangla_digits + digit * 3, 3) + result;  // Prepend digit (3 bytes each)
        value /= 10;
    }
    return result + "\n";  // Add newline
}