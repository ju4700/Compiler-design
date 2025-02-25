### **BPL** (Bangla Programming Language) is a custom compiler where **keywords, variables, and syntax** are written in **Bangla**. Built with **C++ (Flex, Bison, and LLVM)**, this compiler allows Bangla-speaking developers to write and execute code in their native language.  

🔹 **Key Features:**  
✅ **Fully Bangla-based syntax** (variables, functions, conditionals)  
✅ **Lexical & syntax analysis** using **Flex & Bison**  
✅ **Semantic analysis & type checking**  
✅ **Code generation via LLVM IR**  
✅ **Cross-platform support** (Windows & Linux)  
✅ **Unicode support for Bangla identifiers**  

💻 **Developed by [ju4700 (Jalal Uddin)](https://github.com/ju4700)**  

---

## **Table of Contents**
- [ Installation (Windows & Linux)](#-installation-windows--linux)
- [ Language Syntax](#-language-syntax)
- [ Compilation Workflow](#️-compilation-workflow)
- [ Project Architecture](#-project-architecture)
- [ Contribution Guidelines](#-contribution-guidelines)
- [ Roadmap & Future Enhancements](#-roadmap--future-enhancements)
- [ License](#-license)

---

##  **Installation (Windows & Linux)**  
### **🔹 Windows (Using MSYS2 & Clang)**  
#### **Step 1: Install Required Tools**  
1️⃣ Download and install **MSYS2** from [msys2.org](https://www.msys2.org/).  
2️⃣ Open **MSYS2 MinGW 64-bit terminal** and install dependencies:  
   ```sh
   pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-clang flex bison make git
   ```
3️⃣ Clone the repository:  
   ```sh
   git clone https://github.com/ju4700/bangla-compiler.git
   cd bangla-compiler
   ```
4️⃣ Build the compiler:  
   ```sh
   make
   ```
5️⃣ Run a Bangla script:  
   ```sh
   ./bpl examples/sample.bgl
   ```

---

### **🔹 Linux (Ubuntu/Debian-based Distros)**
#### **Step 1: Install Required Dependencies**  
```sh
sudo apt update
sudo apt install build-essential flex bison clang llvm cmake git
```
#### **Step 2: Clone and Build the Compiler**  
```sh
git clone https://github.com/ju4700/bangla-compiler.git
cd bangla-compiler
make
```
#### **Step 3: Run a Bangla Script**  
```sh
./bpl examples/sample.bgl
```

---

##  **Language Syntax**
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

##  **Compilation Workflow**
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

##  **Project Architecture**
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

##  **Contribution Guidelines**
 **Want to contribute?** Follow these steps:  
1️⃣ **Fork the repository**   
2️⃣ **Create a feature branch** (`git checkout -b feature-branch`)  
3️⃣ **Commit your changes** (`git commit -m "Added new feature"`)  
4️⃣ **Push to GitHub** (`git push origin feature-branch`) 
5️⃣ **Submit a pull request** for review 🔍  

### **🔹 Coding Standards**
✅ Follow **consistent naming conventions**  
✅ Ensure **Unicode compatibility** for Bangla syntax  
✅ Write **unit tests** for new features  
✅ Maintain **detailed documentation** for changes  

---

##  **Roadmap & Future Enhancements**
✅ **Phase 1**: Core Syntax & Compiler Architecture  
✅ **Phase 2**: AST Optimization & Type Checking  
✅ **Phase 3**: LLVM Backend for Efficient Code Generation  
🔜 **Phase 4**: Object-Oriented Programming (OOP) Support  
🔜 **Phase 5**: File Handling, Arrays, and Advanced Data Structures  
🔜 **Phase 6**: Cross-Platform Compilation (WebAssembly, JVM)  
🔜 **Phase 7**: IDE Integration & Debugging Support  

---

##  **License**
📄 **MIT License**  
This project is **open-source**. Feel free to modify and distribute it!  

---

### 👤 **Author**  
💻 **Developed by [ju4700 (Jalal Uddin)](https://github.com/ju4700)**  
