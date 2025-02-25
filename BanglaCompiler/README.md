# Bangla Compiler
A compiler for Bangla-script programs.

## Setup
1. Install: `sudo dnf install gcc-c++ flex bison llvm-devel cmake`
2. Build: `mkdir build && cd build && cmake .. && make`

## Usage
Compile: `./bcl test/basic.bgl`
Run: `./program`

## Syntax
- Variables: `সংখ্যা ক = ১০;`
- If-else: `যদি (ক > ৫) { দেখাও(ক); } নাহলে { দেখাও(৫); }`
- While: `যতক্ষণ (ক > ০) { ক = ক - ১; }`
