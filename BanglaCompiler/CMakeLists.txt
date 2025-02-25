cmake_minimum_required(VERSION 3.10)
project(BanglaCompiler)

set(CMAKE_CXX_STANDARD 17)
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
llvm_map_components_to_libnames(llvm_libs core support irreader)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)
FLEX_TARGET(Lexer src/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c)
BISON_TARGET(Parser src/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.c DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.h)
ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

# Ensure generated files are treated as C++
set_source_files_properties(${FLEX_Lexer_OUTPUTS} ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.c PROPERTIES LANGUAGE CXX)

# Add src/ to include path
include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(bcl
    ${FLEX_Lexer_OUTPUTS}  # lex.yy.c
    ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.c  # parser.tab.c
    src/ast.cpp
    src/semantic.cpp
    src/codegen.cpp
    src/main.cpp
)

target_link_libraries(bcl ${llvm_libs} fl)