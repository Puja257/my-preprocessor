# My Preprocessor – C Project

## Project Overview
My Preprocessor is a C-based application that implements basic preprocessor functionalities. It processes a C source file and generates an expanded source file with a '.i' extension.

The project demonstrates how a C preprocessor works through three major operations:

## Features
- **Comment Removal:** Removes single-line (`//`) and multi-line (`/* */`) comments from the source code.
- **File Inclusion:** Handles header file inclusion by inserting the contents of included files.
- **Macro Substitution:** Identifies macros defined using `#define` and replaces their occurrences with corresponding values.

## Technologies Used
- Programming Language: C
- Operating System: Ubuntu Linux
- Compiler: GCC
- Build Tool: Makefile

## Project Structure
- 'main.c' – Main program
- `comment_removal.c / .h` – Comment removal functionality
- `file_inclusion.c / .h` – Header file inclusion
- `macro_handler.c / .h` – Macro substitution
- `Makefile` – Automates compilation

## How to Compile and Run

1. Clone or download the repository.
2. Open the project directory in the terminal.
3. Compile using:
make

4. Run the executable using the appropriate command.
5. Provide a C source file as input and generate the processed `.i` file.

## Learning Outcomes
- Understanding C preprocessor concepts.
- Working with file handling in C.
- Implementing modular programming using multiple `.c` and `.h` files.
- Using Makefile for automated compilation.

## Author
Pooja Patil

Electronics and Communication Engineering
