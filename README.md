# Bangla Compiler

A simple compiler for a Bangla-scripted programming language, built with Flex, Bison, and LLVM. This project translates Bangla source code into executable binaries and supports basic constructs like variables, conditionals, and output in Bangla numerals (e.g., ১০ instead of 10).

## Overview

The Bangla Compiler (`bcl`) allows users to write programs in Bangla script, leveraging a custom grammar and LLVM-based code generation. It supports integer variables, if-else statements, and printing values, with output formatted in Bangla digits. This project serves as a proof-of-concept for localized programming languages and as an educational tool for compiler design.

## Features

- **Bangla Script Support:** Write code using Bangla keywords (e.g., `সংখ্যা` for integer, `যদি` for if, `দেখাও` for print).
- **Integer Operations:** Basic arithmetic and comparisons (e.g., `+`, `>`, `=`).
- **Conditionals:** Support for if and if-else statements with Bangla syntax (`যদি`, `নাহলে`).
- **Bangla Output:** Outputs integers in Bangla numerals (e.g., `১০` for 10).
- **LLVM Backend:** Generates executable binaries via LLVM IR.

## Installation

### Prerequisites

- CMake (>= 3.10)
- GCC/G++ or Clang (C++17 support)
- Flex (>= 2.6.4)
- Bison (>= 3.8.2)
- LLVM (with development libraries, e.g., `libllvm-dev` on Ubuntu)

### Build Instructions

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/yourusername/BanglaCompiler.git
   cd BanglaCompiler
   ```

2. **Create Build Directory:**

   ```bash
   mkdir build
   cd build
   ```

3. **Run CMake:**

   ```bash
   cmake .. -Wno-dev
   ```

4. **Build the Compiler:**

   ```bash
   make
   ```

5. **Verify Installation:**

   The executable `bcl` should be in the build directory:

   ```bash
   ls -l bcl
   ```

## Usage

### Writing Bangla Code

Create a `.bgl` file with Bangla script. Example (`basic.bgl`):

```plaintext
সংখ্যা ক = ১০;
যদি (ক > ৫) {
    দেখাও(ক);
} নাহলে {
    দেখাও(৫);
}
```

### Compiling and Running

1. **Compile the Code:**

   ```bash
   ./bcl ../test/basic.bgl
   ```

   Outputs diagnostic messages and generates the program.

2. **Run the Program:**

   ```bash
   ./program
   ```

   **Expected output:** ১০ (Bangla digits for 10).

### Example Output

For `basic.bgl`:

```bash
./bcl ../test/basic.bgl
NUMBER
IDENTIFIER ক
ASSIGN
INTEGER 10
SEMICOLON
IF
LPAREN
IDENTIFIER ক
GT
INTEGER 5
RPAREN
LBRACE
PRINT
LPAREN
IDENTIFIER ক
RPAREN
SEMICOLON
RBRACE
ELSE
LBRACE
PRINT
LPAREN
INTEGER 5
RPAREN
SEMICOLON
RBRACE
Semantic analysis passed
Compilation complete. Run ./program
```

```bash
./program
১০
```

## Project Structure

- `src/`: Source files
  - `lexer.l`: Lexical analyzer (Flex)
  - `parser.y`: Syntax parser (Bison)
  - `ast.h`, `ast.cpp`: Abstract Syntax Tree
  - `semantic.h`, `semantic.cpp`: Semantic analysis
  - `codegen.h`, `codegen.cpp`: Code generation (LLVM)
  - `main.cpp`: Entry point
- `build/`: Build directory (generated)
- `test/`: Test files (e.g., `basic.bgl`)
- `CMakeLists.txt`: Build configuration

## Limitations

- **Static Integer Output:** Currently, integer variables are statically converted to Bangla digits (e.g., `১০` for 10). Dynamic runtime conversion is planned.
- **Basic Features:** Supports only integers, simple conditionals, and printing. Future enhancements include loops, functions, and more data types.

## Contributing

Contributions are welcome! To contribute:

1. Fork the repository.
2. Create a branch (`git checkout -b feature/your-feature`).
3. Commit changes (`git commit -m "Add your feature"`).
4. Push to your fork (`git push origin feature/your-feature`).
5. Open a Pull Request.

## Development Notes

- Use `bison -v` to debug grammar conflicts (`parser.output`).
- Ensure LLVM compatibility with your system’s version.

## License

This project is licensed under the MIT License. See LICENSE for details.

## Acknowledgments

Built with inspiration from compiler design tutorials and the xAI community. Thanks to Flex, Bison, and LLVM developers for their amazing tools.
