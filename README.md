# **📢 Bangla Programming Language Compiler (BPL)**  
🚀 **BPL** (Bangla Programming Language) is a **custom programming language** where **keywords, variable names, and syntax** are written in **Bangla**. This compiler, built with **C++ (Flex & Bison)**, converts Bangla source code into an **executable file**.  

**Made by [ju4700 (Jalal Uddin)](https://github.com/ju4700)**  

---

## **📖 Table of Contents**  
- [📌 Features](#-features)  
- [⚙️ Installation](#️-installation)  
- [📝 Language Syntax](#-language-syntax)  
- [🖥️ Compilation Process](#️-compilation-process)  
- [📂 Project Structure](#-project-structure)  
- [🔧 Contributing](#-contributing)  
- [🚀 Future Improvements](#-future-improvements)  
- [📜 License](#-license)  

---

## **📌 Features**  
✅ Write programs entirely in **Bangla**  
✅ **Lexical analysis** with **Flex**  
✅ **Syntax parsing** with **Bison**  
✅ **Semantic analysis** for type-checking  
✅ **Code generation** using LLVM IR  
✅ **Unicode support** for Bangla variable names  
✅ **Standard Library** (Print, Input, Math, String functions)  

---

## **⚙️ Installation**  
### **🔹 Prerequisites**  
Make sure you have the following installed:  
- **GCC** (for compiling C++ code)  
- **Flex** (for lexical analysis)  
- **Bison** (for syntax parsing)  
- **LLVM** (for IR generation)  
- **CMake** (for build system)  

### **🔹 Steps to Install**  
```sh
# Clone the repository
git clone https://github.com/ju4700/bangla-compiler.git
cd bangla-compiler

# Install dependencies
sudo apt update
sudo apt install flex bison clang llvm cmake g++

# Build the compiler
make

# Run the compiler on a sample program
./bpl sample.bgl
```

---

## **📝 Language Syntax**  
### **🔹 Variables**  
```plaintext
সংখ্যা ক = ১০;
দশমিক পি = ৩.১৪;
স্ট্রিং বার্তা = "হ্যালো বিশ্ব";
বুলিয়ান সত্যতা = সত্য;
```

### **🔹 Conditionals**  
```plaintext
যদি (ক > ৫) {
    দেখাও("ক বড় সংখ্যা");
} নাহলে {
    দেখাও("ক ছোট সংখ্যা");
}
```

### **🔹 Loops**  
```plaintext
সংখ্যা ক = ১;
যতক্ষণ (ক <= ৫) {
    দেখাও(ক);
    ক = ক + ১;
}
```

### **🔹 Functions**  
```plaintext
ফাংশন যোগ(সংখ্যা ক, সংখ্যা খ) {
    ফিরিয়ে দাও (ক + খ);
}

সংখ্যা ফলাফল = যোগ(৫, ১০);
দেখাও(ফলাফল);
```

### **🔹 Input/Output**  
```plaintext
সংখ্যা বয়স = ইনপুট();
দেখাও("আপনার বয়স: " + বয়স);
```

---

## **🖥️ Compilation Process**  
### **🔹 Steps**  
1️⃣ **Write Bangla Code** (`sample.bgl`)  
2️⃣ **Run Compiler**: `./bpl sample.bgl`  
3️⃣ **Compiler Stages:**  
   - 🔹 **Lexical Analysis** (Tokenization)  
   - 🔹 **Parsing** (AST Generation)  
   - 🔹 **Semantic Analysis** (Type Checking)  
   - 🔹 **Code Generation** (LLVM IR)  
   - 🔹 **Linking & Execution**  

### **🔹 Example Compilation**  
```sh
./bpl sample.bgl
./output
```

---

## **📂 Project Structure**  
```
BanglaCompiler/
│── src/
│   ├── lexer.cpp          # Lexical analysis (Flex)
│   ├── parser.cpp         # Syntax analysis (Bison)
│   ├── ast.cpp            # Abstract Syntax Tree
│   ├── semantic.cpp       # Type checking & scope management
│   ├── codegen.cpp        # LLVM IR generation
│   ├── main.cpp           # Compiler driver
│── include/
│   ├── lexer.h
│   ├── parser.h
│   ├── ast.h
│   ├── semantic.h
│   ├── codegen.h
│── test/                  # Test cases for validation
│── docs/                  # Documentation & language spec
│── examples/              # Sample Bangla programs
│── Makefile               # Build system
│── README.md              # Project Documentation
```

---

## **🔧 Contributing**  
🚀 **Want to contribute?** Follow these steps:  
1. **Fork the repository**  
2. **Create a feature branch**  
3. **Commit changes**  
4. **Submit a pull request**  

### **🔹 Contribution Guidelines**  
✅ Follow **clean code principles**  
✅ Ensure **Unicode support** for Bangla syntax  
✅ Write **unit tests** for new features  
✅ Document **any new syntax changes**  

---

## **🚀 Future Improvements**  
🔹 **Add Object-Oriented Programming (OOP) Support**  
🔹 **Implement File I/O Operations**  
🔹 **Add Standard Libraries (Math, String, System)**  
🔹 **Support Function Overloading & Recursion**  
🔹 **Extend Compiler Backend (WebAssembly, JVM)**  
🔹 **Create an IDE Plugin for BPL**  

---

## **📜 License**  
📄 **MIT License**  
This project is **open-source**. Feel free to modify and distribute it!  

---

🔥 **Happy Coding in Bangla!** 🇧🇩✨  
💻 **Made by [ju4700 (Jalal Uddin)](https://github.com/ju4700)**
