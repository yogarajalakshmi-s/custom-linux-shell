# Custom Linux Shell (`mysh`)

## Overview

`mysh` is a simple custom Linux shell implemented in C. It supports basic command execution such as running standard Linux commands (`ls`, `pwd`, etc.), along with built-in commands. This project demonstrates core shell functionality including command parsing, execution, and builtin command handling.

---

## Project Structure
```bash
├── custom-linux-shell
│    ├── src
│    │  ├── main.c
│    │  ├── parser.c # Command parsing implementation 
│    │  ├── executor.c # Command execution logic
│    │  ├── builtins.c # Implementation of shell built-in commands
│    │  ├── utils.c # Utility functions
│    ├── include
│       ├── parser.h # Parser function declarations
│       ├── executor.h # Executor function declarations
│       ├── builtins.h # Utility function declarations
│       ├── utils.h # Built-in command declarations
├── 
├── Makefile # Build script for compiling the shell
├── README.md
└── .gitignore
```


---

## Features
- Execute standard Linux commands (e.g., `ls`, `pwd`, `cat`)
- Basic parsing of command line inputs
- Support for built-in commands
- Modular code structure separating parsing, execution, and utilities

---

## How to Build and Run

1. Clone the repository or download the source code.
2. Open a terminal and navigate to the project directory.
3. Build the shell by running:
   ```bash
   make
4. Run the executable
   ```bash
   ./mysh

