#!/bin/bash

# Compile all .c files into .o files
gcc -c *.c

# Create static library liball.a from all .o files
ar rcs liball.a *.o
