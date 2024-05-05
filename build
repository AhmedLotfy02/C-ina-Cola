#!/bin/bash

# Run Bison
bison main.y -d

# Run Flex
flex main.l

# Compile with GCC
gcc -g main.tab.c lex.yy.c -o compiler

# Execute the compiled program
./compiler