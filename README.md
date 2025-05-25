# Custom Linux Shell (`mysh`)

## Overview

`mysh` is a simple yet powerful custom Linux shell implemented in C. It replicates basic behavior of standard shells like `bash` or `sh`, allowing users to run Linux commands, built-in shell functions, and now supports features like piping, redirection, and background execution.  
  
This project demonstrates core systems programming concepts including process creation, file descriptor manipulation, command parsing, and signal handling.


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
- Execute standard Linux commands (e.g., ls, pwd, cat)
- Built-in commands (e.g., cd, exit)
- Pipes (|) to connect multiple commands
- Background process execution using &
- Input (<) and output (>) redirection
- Modular, extensible design

---

## How to Build and Run

1. Clone the repository or download the source code.
2. Open a terminal and navigate to the project directory.
3. Build the shell by running:
   ```bash
   make
4. Run the executable and test the above features
   ```bash
   ./mysh

