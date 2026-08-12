# CS509 Software Lab Repository

## Repository Overview

This repository contains the laboratory assignments completed as part of the **CS509 Software Laboratory** course at **IIT Ropar**.

Each assignment is maintained in an independent directory containing:

- Driver programs
- Header files
- Source files
- Test cases
- Output files
- Assignment-specific documentation

A common wrapper program is provided to allow all assignments to be executed through a single menu-driven interface.

---

## Pair Details

| Field | Details |
|------|------|
| Member 1 | Shubham Kohli |
| Roll Number | 2026CSM1036 |
| Member 2 | Dheeraj Dev |
| Roll Number | 2026CSM1010 |

---

## Language and Development Environment

| Component | Details |
|------|------|
| Programming Language | C++ |
| Compiler | GNU g++ (MinGW-w64) |
| Operating System | Windows 11 |
| IDE | Visual Studio Code |
| C++ Standard | C++17 |

---

## Assignment Directory Structure

Each assignment contains the following subdirectories:

| Directory | Description |
|------|------|
| `driver/` | Driver module containing the `main()` function |
| `include/` | Header files |
| `src/` | Source files |
| `tests/` | Input test files |

---

# Common Wrapper

The common wrapper provides a centralized interface for executing the assignments.

### Build

```bash
g++ common_wrapper/common_wrapper.cpp -o common_wrapper.exe
```

### Execute (Windows)

```powershell
.\common_wrapper.exe
```

### Execute (Linux)

```bash
./common_wrapper
```

---

## Wrapper Menu

```text
===== CS509 LAB WRAPPER =====

1. Assignment 1
2. Assignment 2
0. Exit

Enter your choice:
```

---

# Assignment 1

### Topics Covered

- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- Single-Source Shortest Path (SSSP)

# Assignment 2

### Topics Covered

- Triangle Counting
- Between Centrality
- Connected Components

---

## Development Workflow

1. Implement the algorithm.
2. Add the corresponding header file.
3. Add test cases.
4. Compile the project.
5. Execute the program.
6. Verify the output.

---

## Authors

- Shubham Kohli (2026CSM1036)
- Dheeraj Dev (2026CSM1010)
