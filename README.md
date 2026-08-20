# consolelibrary
ConsoleLibrary is open source terminal utility to keep track of books, it allows you to record the author, title and year of publication. Utility working on C.

Requirements:
gcc, make(optional).

Makefile:
built files moves to "bin" folder
object files (.o) moves to "build" folder

make - just build
make clean - delete "build" folder
make run - build and launch "library"
make rebuild - rebuild source files

Build without make:
gcc -Wall -Wextra -std=c17 -g -I. src/main.c -o library

Source files:
src/main.c - C. Main file
src/IOF.h - Header for Input/Output Files

Program files:
books.txt - "library" writing book data at this file
