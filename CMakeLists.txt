cmake_minimum_required(VERSION 3.10)
project(compiler LANGUAGES CXX)

set(COMPILER_LIBS ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(src)

set(COMMON_LIBS lexer)

add_executable(compiler.exe src/compiler.cpp )
target_link_libraries(compiler.exe PRIVATE ${COMMON_LIBS})
target_compile_features(compiler.exe PRIVATE cxx_std_11 )
target_include_directories(compiler.exe PRIVATE ${COMPILER_LIBS}/lexer)
# target_include_directories(compiler.exe PRIVATE ${COMPILER_LIBS}/statement)
# target_include_directories(compiler.exe PRIVATE ${COMPILER_LIBS}/table)
