# CP Analyzer (C++ Code Analyzer)

A simple C++ project that analyzes source code and detects common competitive programming patterns such as **loops, recursion, nesting and time complexity estimation**.

This project is built to understand **how real C++ code is structured**, how to read files, and how static analysis works at a basic level.

---

##  What this analyzer does

Currently, the analyzer can:

- Read a `.cpp` file line by line
- Detect:
  - `for` loops
  - Nested loops
  - Recursive function calls
  - Estimate time complexity using heuristics
- Ignore:
  - Single-line comments (`//`)
  - Multi-line comments (`/* ... */`)
- Track braces `{}` to understand scope properly

---

## How it works 

1. The program takes a C++ source file as input
2. It scans the file line by line
3. While scanning, it:
   - Keeps track of braces to understand blocks
   - Detects function calls inside their own function (recursion)
   - Counts loops and checks if they are nested
4. The logic is separated into:
   - `main.cpp` → program flow
   - `parser.h` → declarations (what the parser can do)
   - `parser.cpp` → actual parsing logic

   The analysis is **heuristic-based**, not a compiler-level parsing.

---

## Project structure

```

CP-Analyzer/
│
├── main.cpp
├── analyzer/
│   ├── parser.h
│   └── parser.cpp
└── input/
    └── solution.cpp

```
---

## Why I built this 

As a **2nd year BTech student**, I wanted a project that goes beyond solving problems on platforms and instead focuses on **how code itself can be analyzed**.

This project helped me:
- Understand **file handling and string parsing in C++**.
- Learn **static code analysis concepts**.
- Learn how **compilers and analyzers think**.
- Practice **clean project structure** using multiple `.cpp` and `.h` files.
- Apply concepts like **encapsulation** in a real way.

---

## How to run

1. Clone the repository
2. Place the C++ file you want to analyze inside the `input` folder
3. Compile the project:

```bash
g++ main.cpp parser.cpp -o cp-analyzer

```

4. Run the project :

```bash
./cp-analyzer

```

---

## Known Limitations

- Does not fully parse C++ syntax (no AST)
- Inline block comments inside code lines are handled in a basic way
- `for` keywords inside strings may cause false positives
- Does not estimate recursion depth or recursive complexity
- Assumes typical competitive programming patterns

---

## Design Choices

- Uses heuristics instead of full parsing for simplicity
- Separates logic into a parser module for clean architecture
- Keeps `main.cpp` minimal and focused on orchestration

--- 

## Future Improvements

- Improve comment handling edge cases
- Support multiple functions
- Detect recursive complexity patterns
- Extend support to `while` loops
- Add unit tests




