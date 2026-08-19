# CS509 – Assignment 3 Buddy Task

## Gradient Descent and Maxflow-Mincut

This repository contains the implementation of the **CS509 Assignment 3 Buddy Task**.

The buddy task consists of two algorithms:

- Gradient Descent
- Maxflow-Mincut

The implementations are integrated into the existing CS509 repository and are accessible through the common wrapper.

---

## Team Members

- **Shubham Kohli** – 2026CSM1036
- **Dheeraj Dev** – 2026CSM1010

---

## Technologies Used

- **Language:** C++17
- **Compiler:** GNU g++
- **Operating System:** Windows 11
- **IDE:** Visual Studio Code
- **Build System:** Makefile / MinGW

---

## Repository Structure

```text
Assignment3/
│
├── driver/
│   └── main.cpp
│
├── include/
│   ├── assignment3.h
│   ├── gradient_descent.h
│   └── maxflow.h
│
├── src/
│   ├── gradient_descent.cpp
│   ├── maxflow.cpp
│   └── maxflow_input.cpp
│
└── tests/
    ├── gradient_descent/
    │   ├── gd_01.txt
    │   ├── gd_02.txt
    │   ├── gd_03.txt
    │   ├── gd_04.txt
    │   └── gd_05.txt
    │
    └── maxflow/
        ├── maxflow_10.txt
        ├── maxflow_100.txt
        ├── maxflow_1000.txt
        ├── maxflow_10000.txt
        └── maxflow_50000.txt
```

## Gradient Descent

The Gradient Descent implementation represents the objective function as a generic one-variable polynomial:

`f(x) = c₀ + c₁x + c₂x² + ... + cₙxⁿ`

The derivative is evaluated directly from the coefficient vector. At each iteration, the value of `x` is updated using:

`x_new = x − learning_rate × f'(x)`

The algorithm terminates when either:

- The absolute derivative is within the specified tolerance.
- The maximum number of iterations is reached.

The implementation uses the same polynomial evaluation and derivative logic for the required degrees:

- Degree 2
- Degree 4
- Degree 6
- Degree 8
- Degree 10

### Gradient Descent Test Results

| Test File | Degree | Final x | Final f(x) | Iterations | Time (ms) | Converged | Status |
|-----------|-------:|--------:|-----------:|-----------:|----------:|:---------:|:------:|
| `gd_01.txt` | 6* | 0.000000 | 0.000000 | 349 | 0.054130 | True | Not Valid |
| `gd_02.txt` | 4 | 0.000000 | 0.000000 | 180 | 0.017606 | True | Pass |
| `gd_03.txt` | 6 | 0.000000 | 0.000000 | 349 | 0.030024 | True | Pass |
| `gd_04.txt` | 8 | 0.000000 | 0.000000 | 948 | 0.098185 | True | Pass |
| `gd_05.txt` | 10 | 0.000000 | 0.000000 | 2364 | 0.271562 | True | Pass |

### Gradient Descent Discussion

For `gd_02.txt` through `gd_05.txt`, the implementation converged to `x ≈ 0` with `f(x) ≈ 0`, matching the expected global minimum for those functions.

The iteration count and execution time increase for the higher-degree functions and their corresponding convergence requirements.

### Note on `gd_01.txt`

The supplied `gd_01.txt` currently contains the degree-6 parameters corresponding to `gd_03.txt` rather than the required degree-2 function:

`x² − 6x + 9`

The expected minimum for the specified `gd_01` function is:

`x* = 3`

Therefore, the recorded `gd_01.txt` result reflects the file currently present in the repository and is marked **Not Valid**. The input file should be corrected before final submission if strict compliance with the prescribed test definitions is required.

## Maxflow-Mincut

The Maxflow-Mincut implementation uses **Dinic's algorithm**.

The input graph is directed and contains:

- Positive integer capacities
- A source vertex
- A sink vertex

The weighted CSR graph is converted into an internal residual network using:

- Forward edges with their original capacities
- Reverse edges with initially zero capacity

Dinic's algorithm repeatedly performs:

1. **BFS** to construct the level graph.
2. **DFS** to send blocking flow through the level graph.
3. Repeats until the sink is no longer reachable in the residual graph.

When the sink is no longer reachable, the maximum flow has been obtained.

### Minimum Cut Extraction

The minimum cut is extracted from the final residual graph.

A traversal starting from the source identifies all vertices that remain reachable through positive residual capacity.

The original edges crossing from the reachable side to the unreachable side form the reported minimum cut. Their capacities are summed to obtain the cut capacity.

The correctness condition is:

`Maximum Flow = Minimum Cut Capacity`

---

## Maxflow-Mincut Test Results

The implementation was tested using the five required graph sizes.

| Test File | Vertices (V) | Edges (E) | Source | Sink | Flow | Cut Capacity | Time (ms) | Status |
|-----------|-------------:|----------:|-------:|-----:|-----:|-------------:|----------:|:------:|
| `maxflow_10.txt` | 10 | 18 | 0 | 9 | 22 | 22 | 0.012839 | Pass |
| `maxflow_100.txt` | 100 | 217 | 0 | 99 | 30 | 30 | 0.066669 | Pass |
| `maxflow_1000.txt` | 1,000 | 2,296 | 0 | 999 | 45 | 45 | 0.533922 | Pass |
| `maxflow_10000.txt` | 10,000 | 23,495 | 0 | 9,999 | 28 | 28 | 5.306930 | Pass |
| `maxflow_50000.txt` | 50,000 | 117,495 | 0 | 49,999 | 25 | 25 | 27.749500 | Pass |

### Maxflow-Mincut Discussion

All five required benchmark graphs produced a maximum-flow value equal to the reported minimum-cut capacity.

The measured execution time increased from approximately `0.012839 ms` for the 10-vertex graph to `27.749500 ms` for the 50,000-vertex graph.

All five required graph sizes completed successfully.

### Timing

The reported time measures the algorithm execution section rather than file I/O.

CSR preparation is performed before timing.

The timed section includes:

- Residual-network construction
- Dinic's maximum-flow computation
- Minimum-cut extraction

File reading and input preparation are excluded from the measured execution time.

## Timing Methodology

The reported execution times measure only the algorithm execution section and exclude file I/O and input preparation.

### Gradient Descent

For Gradient Descent, timing starts after the input file has been read and parsed.

The measured section includes the Gradient Descent iterations and polynomial/derivative evaluations.

### Maxflow-Mincut

For Maxflow-Mincut, CSR preparation is completed before timing begins.

The timed section includes:

- Residual-network construction
- Dinic's maximum-flow computation
- Minimum-cut extraction

File reading, input parsing, and CSR preparation are excluded from the measured execution time.

---

## Correctness Verification

### Gradient Descent

Gradient Descent correctness was checked against the supplied expected minima for the valid degree-4, degree-6, degree-8, and degree-10 test cases.

All valid Gradient Descent test cases converged successfully.

The `gd_01.txt` test case is currently marked as invalid because the supplied file contains the degree-6 parameters corresponding to `gd_03.txt` instead of the required degree-2 test function.

### Maxflow-Mincut

Maxflow-Mincut correctness was verified using the maximum-flow/minimum-cut equality.

For every required test graph:

`Maximum Flow = Minimum Cut Capacity`

All five Maxflow-Mincut test cases satisfied this equality.


## Performance Summary

| Task | Smallest Test | Largest Test | Observed Trend |
|------|---------------|--------------|----------------|
| Gradient Descent | 0.017606 ms (degree 4) | 0.271562 ms (degree 10) | Higher degree and iteration count increase computation |
| Maxflow-Mincut | 0.012839 ms (10 vertices) | 27.749500 ms (50,000 vertices) | Runtime increases with graph size and edge count |

The results show the expected computational growth for both algorithms.

For Gradient Descent, higher-degree polynomial functions require more computation per iteration and may require more iterations to satisfy the convergence condition.

For Maxflow-Mincut, the execution time increases as the size and edge count of the input graph increase because the residual network and flow computation become larger.


## Conclusion

The Assignment 3 Buddy Task successfully implements both required algorithms: Gradient Descent and Maxflow-Mincut.

Gradient Descent uses a generic polynomial optimization approach and successfully converges for all valid supplied test cases.

Maxflow-Mincut uses Dinic's algorithm with residual-network processing and minimum-cut extraction. All five required Maxflow-Mincut test cases satisfied the maximum-flow/minimum-cut equality.

The implementations were integrated into the existing CS509 repository and tested using the required input sizes.

The performance results show increasing computation with higher polynomial complexity for Gradient Descent and increasing graph size and edge count for Maxflow-Mincut.

One test-data issue remains in the supplied repository: `gd_01.txt` currently contains the parameters for the degree-6 `gd_03` test instead of the required degree-2 function. This should be corrected before final submission if strict compliance with the prescribed test definitions is required.
