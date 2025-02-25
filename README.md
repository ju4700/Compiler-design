# **Bangla Programming Language Compiler (BPL)**
> **A modern, Unicode-compliant programming language with Bangla syntax.**  

🚀 **BPL** (Bangla Programming Language) is a custom programming language designed for **native Bangla syntax and variable naming**. Built with **C++ (Flex, Bison, and LLVM)**, this compiler translates Bangla source code into executable machine instructions, making programming more accessible to Bangla-speaking developers.  

💡 **Key Features:**  
✅ **Fully Bangla-based Syntax** (Keywords, Variables, Functions)  
✅ **Lexical Analysis & Parsing** (via **Flex & Bison**)  
✅ **Semantic Analysis & Type Checking**  
✅ **Intermediate Representation (IR) with LLVM**  
✅ **Unicode Support for Bangla Identifiers**  
✅ **Standard Library for I/O, Math, and Strings**  
✅ **Cross-Platform Compilation & Execution**  

---

## 📖 **Table of Contents**
- [🚀 Installation](#-installation)
- [📝 Language Syntax](#-language-syntax)
- [⚙️ Compilation Workflow](#️-compilation-workflow)
- [📂 Project Architecture](#-project-architecture)
- [🔧 Contribution Guidelines](#-contribution-guidelines)
- [🌍 Roadmap & Future Enhancements](#-roadmap--future-enhancements)
- [📜 License](#-license)

---

## 🚀 **Installation**
### 🔹 **Prerequisites**
Ensure the following dependencies are installed:  
- **C++ Compiler (GCC/Clang/MSVC)**  
- **Flex** (Lexical Analysis)  
- **Bison** (Parser Generation)  
- **LLVM** (Intermediate Representation & CodeGen)  
- **CMake** (Build System)  

### 🔹 **Setup Instructions**
```sh
# Clone the repository
git clone https://github.com/ju4700/bangla-compiler.git
cd bangla-compiler

# Install required dependencies
sudo apt update
sudo apt install flex bison clang llvm cmake g++

# Build the compiler
make

# Run the compiler on a sample Bangla script
./bpl examples/sample.bgl
```

---

## 📝 **Language Syntax**
### 🔹 **Variable Declaration**
```plaintext
সংখ্যা ক = ১০;
দশমিক পি = ৩.১৪;
স্ট্রিং বার্তা = "হ্যালো বিশ্ব";
বুলিয়ান সত্যতা = সত্য;
```

### 🔹 **Conditional Statements**
```plaintext
যদি (ক > ৫) {
    দেখাও("ক বড় সংখ্যা");
} নাহলে {
    দেখাও("ক ছোট সংখ্যা");
}
```

### 🔹 **Looping Constructs**
```plaintext
সংখ্যা ক = ১;
যতক্ষণ (ক <= ৫) {
    দেখাও(ক);
    ক = ক + ১;
}
```

### 🔹 **Function Definitions**
```plaintext
ফাংশন যোগ(সংখ্যা ক, সংখ্যা খ) {
    ফিরিয়ে দাও (ক + খ);
}

সংখ্যা ফলাফল = যোগ(৫, ১০);
দেখাও(ফলাফল);
```

### 🔹 **User Input/Output**
```plaintext
সংখ্যা বয়স = ইনপুট();
দেখাও("আপনার বয়স: " + বয়স);
```

---

## ⚙️ **Compilation Workflow**
### 🔹 **Processing Steps**
1️⃣ **Lexical Analysis** → Converts code into tokens.  
2️⃣ **Parsing** → Builds an **Abstract Syntax Tree (AST)**.  
3️⃣ **Semantic Analysis** → Type checking & scope validation.  
4️⃣ **Intermediate Representation (LLVM IR)** → Optimized code generation.  
5️⃣ **Machine Code Generation** → Produces executable binaries.  

### 🔹 **Running the Compiler**
```sh
./bpl source.bgl
./output
```

---

## 📂 **Project Architecture**
```
BanglaCompiler/
│── src/
│   ├── lexer.cpp          # Tokenization using Flex
│   ├── parser.cpp         # Syntax parsing using Bison
│   ├── ast.cpp            # Abstract Syntax Tree (AST) construction
│   ├── semantic.cpp       # Type checking & scope management
│   ├── codegen.cpp        # LLVM IR generation
│   ├── main.cpp           # Compiler driver & CLI interface
│── include/
│   ├── lexer.h
│   ├── parser.h
│   ├── ast.h
│   ├── semantic.h
│   ├── codegen.h
│── examples/              # Sample Bangla scripts
│── test/                  # Unit tests for compiler features
│── docs/                  # Documentation & language specification
│── Makefile               # Build automation script
│── README.md              # Project documentation
```

---

## 🔧 **Contribution Guidelines**
🚀 **Want to contribute?** Follow these steps:  
1. **Fork the repository** 📌  
2. **Create a feature branch** (`git checkout -b feature-branch`) 🌿  
3. **Commit your changes** (`git commit -m "Added new feature"`) ✅  
4. **Push to GitHub** (`git push origin feature-branch`) 🚀  
5. **Submit a pull request** for review 🔍  

### **🔹 Coding Standards**
✅ Follow **consistent naming conventions**  
✅ Ensure **Unicode compatibility** for Bangla syntax  
✅ Write **unit tests** for new features  
✅ Maintain **detailed documentation** for changes  

---

## 🌍 **Roadmap & Future Enhancements**
✅ **Phase 1**: Core Syntax & Compiler Architecture  
✅ **Phase 2**: AST Optimization & Type Checking  
✅ **Phase 3**: LLVM Backend for Efficient Code Generation  
🔜 **Phase 4**: Object-Oriented Programming (OOP) Support  
🔜 **Phase 5**: File Handling, Arrays, and Advanced Data Structures  
🔜 **Phase 6**: Cross-Platform Compilation (WebAssembly, JVM)  
🔜 **Phase 7**: IDE Integration & Debugging Support  

---

## 📜 **License**
📄 **MIT License**  
This project is **open-source**. Feel free to modify and distribute it!  

---

### 👤 **Author**  
💻 **Developed by [ju4700 (Jalal Uddin)](https://github.com/ju4700)**   🔥 **Happy Coding in Bangla!** 🇧🇩✨  
