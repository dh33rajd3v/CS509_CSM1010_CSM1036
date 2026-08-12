# Assignment 2

## Assignment Overview

This assignment implements three graph algorithms using the graph infrastructure developed in Assignment 1:

1. **Triangle Counting**
2. **Betweenness Centrality**
3. **Connected Components**

The assignment focuses on implementing the algorithms efficiently using graph representations suitable for sparse graphs and evaluating their performance on graphs of different sizes.

The CSR (Compressed Sparse Row) graph representation developed in Assignment 1 is reused for the graph-based algorithms rather than being reimplemented separately.

---

## Algorithms Implemented

### 1. Triangle Counting

Triangle Counting identifies all sets of three vertices that form a triangle in an undirected graph.

For every vertex, the implementation examines pairs of its neighbors and checks whether an edge exists between those two neighbors. The vertices forming each triangle are stored in sorted order so that the same triangle is not reported multiple times.

The program reports:

- Total number of triangles
- Vertices belonging to each triangle
- Algorithm execution time

#### Complexity

For the implemented approach, the running time depends on the number of vertices, edges, and the way adjacency lists are traversed. The CSR representation provides direct access to the adjacency list of each vertex.

---

### 2. Betweenness Centrality

Betweenness Centrality measures the importance of a vertex based on how frequently it occurs on shortest paths between other pairs of vertices.

The implementation uses a shortest-path based approach to compute the dependency of vertices on shortest paths originating from each source vertex.

The program reports the calculated centrality values along with the algorithm execution time.

#### Complexity

For the implemented Brandes-based approach on an unweighted graph, the expected complexity is:

- **Time:** `O(VE)`
- **Space:** `O(V + E)`

where:

- `V` = number of vertices
- `E` = number of edges

---

### 3. Connected Components

Connected Components determines the separate connected subgraphs present in an undirected graph.

The implementation uses **Breadth-First Search (BFS)**. Vertices are processed in increasing order, and whenever an unvisited vertex is encountered, a new component is started.

Each vertex is assigned a component ID based on the order in which the components are discovered.

The program reports:

- Total number of connected components
- Component ID of each vertex
- Algorithm execution time

#### Complexity

Since every vertex and adjacency entry is processed during the traversal:

- **Time:** `O(V + E)`
- **Space:** `O(V)`

---

## Project Structure

```text
Assignment_2/
│
├── driver/
│   └── graph_driver.cpp
│
├── include/
│   ├── graph_driver.h
│   ├── triangle_counting.h
│   ├── betweenness_centrality.h
│   └── connected_components.h
│
├── src/
│   ├── triangle_counting.cpp
│   ├── betweenness_centrality.cpp
│   └── connected_components.cpp
│
├── tests/
│   ├── triangle_counting/
│   │   ├── tc_10.txt
│   │   ├── tc_100.txt
│   │   ├── tc_10000.txt
│   │   ├── tc_50000.txt
│   │   └── tc_100000.txt
│   │
│   ├── betweenness_centrality/
│   │   ├── bc_10.txt
│   │   ├── bc_100.txt
│   │   ├── bc_10000.txt
│   │   ├── bc_50000.txt
│   │   └── bc_100000.txt
│   │
│   └── connected_components/
│       ├── cc_10.txt
│       ├── cc_100.txt
│       ├── cc_10000.txt
│       ├── cc_50000.txt
│       └── cc_100000.txt
│
├── Makefile
├── .gitignore
└── README.md
```
---
## Execution Time Measurement

The execution time reported by the program corresponds only to the execution of the selected graph algorithm.

The following operations are excluded from the measured time:

- Opening the input file
- Reading the input file
- Parsing the input
- Constructing the CSR representation
- Printing the output

The timer is started after the graph has been converted into CSR format and immediately before the algorithm starts.

It is stopped immediately after the algorithm finishes.

The general timing flow is:
```text

Read Input
    |
    v
Construct CSR
    |
    v
Start Timer
    |
    v
Run Algorithm
    |
    v
Stop Timer
    |
    v
Print Result

```

The execution time is displayed in milliseconds.

For very small test cases, the measured execution time may be displayed as 0 ms because the execution can be shorter than the resolution of the timer.

Test Cases

The algorithms were tested using the required graph sizes:
```text
10
100
10000
50000
100000
```

Separate test cases are provided for:

- Triangle Counting
- Betweenness Centrality
- Connected Components

The smaller test cases were primarily used to verify correctness, while the larger test cases were used to evaluate execution time and scalability.

---

## Results and Test Cases

| Algorithm | Test File | Vertices | Edges | Expected Output | Actual Output | Time | Status |
|---|---|---:|---:|---|---|---:|:---:|
| Triangle Counting | `tc_10.txt` | 10 | 9 | Total triangles | Total triangles: 3<br>Triangles found: (0, 1, 2), (3, 4, 5), (6, 7, 8) | 4 × 10⁻³ ms | Pass |
| Triangle Counting | `tc_100.txt` | 100 | 700 | Total triangles | Total triangles | 741 × 10⁻³ ms | Pass |
| Triangle Counting | `tc_10000.txt` | 10,000 | 100,000 | Total triangles | Total triangles | 100 ms | Pass |
| Triangle Counting | `tc_100000.txt` | 50,000 | 500,000 | Total triangles | Total triangles | 366 ms | Pass |
| Triangle Counting | `tc_50000.txt` | 100,000 | 800,000 | Total triangles | Total triangles | 546 ms | Pass |
| Betweenness Centrality | `bc_10.txt` | 10 | 15 | Centrality per vertex | Centrality per vertex: all vertices = 4.00 | 48 × 10⁻³ ms | Pass |
| Betweenness Centrality | `bc_100.txt` | 100 | 150 | Centrality per vertex | Centrality per vertex | 335 × 10⁻³ ms | Pass |
| Betweenness Centrality | `bc_10000.txt` | 10,000 | 15,000 | Centrality per vertex | Centrality per vertex | 355.506 ms | Pass |
| Betweenness Centrality | `bc_50000.txt` | 50,000 | 75,000 | Centrality per vertex | Centrality per vertex | 30,516.776 ms | Pass |
| Betweenness Centrality | `bc_100000.txt` | 100,000 | 150,000 | Centrality per vertex | Centrality per vertex | 127,801.675 ms | Pass |
| Connected Components | `cc_10.txt` | 10 | 5 | Component per vertex | Total components: 6 | 0 ms | Pass |
| Connected Components | `cc_100.txt` | 100 | 66 | Component per vertex | Component per vertex | 0.0089 ms | Pass |
| Connected Components | `cc_10000.txt` | 10,000 | 9,900 | Component per vertex | Component per vertex | 0.1518 ms | Pass |
| Connected Components | `cc_50000.txt` | 50,000 | 49,500 | Component per vertex | Component per vertex | 0.904 ms | Pass |
| Connected Components | `cc_100000.txt` | 100,000 | 99,000 | Component per vertex | Component per vertex | 1.2526 ms | Pass |

---

## Performance Analysis

### Triangle Counting

Triangle Counting examines neighboring vertices to determine whether they form a triangle.

As the size of the graph increases, the number of adjacency relationships that need to be examined also increases. Therefore, the execution time depends on both the number of vertices and the number of edges in the graph.

```text
Time:  O(VΔ³)
Space: O(V + E)
```

where:

V = number of vertices
E = number of edges
Δ = maximum vertex degree

The O(VΔ³) bound arises because a vertex can have up to O(Δ²) pairs of neighbors, and checking whether the third edge exists can require an O(Δ) linear scan of an adjacency list.

The CSR representation allows the adjacency lists to be accessed efficiently using row_ptr and col_idx.

### Betweenness Centrality

Betweenness Centrality performs shortest-path processing from every source vertex.

For the implemented unweighted approach, the shortest-path information from each source is used to calculate the dependency values and subsequently determine the centrality of every vertex.

The expected complexity is:

```text
Time:  O(VE)
Space: O(V + E)
```

where V is the number of vertices and E is the number of edges.

Since the shortest-path computation is performed for every vertex, the computational cost increases significantly as the graph size grows.

### Connected Components

Connected Components uses Breadth-First Search to identify all connected components of the graph.

Each vertex is visited once, and the adjacency entries of the vertices are traversed during the BFS operations.

Therefore, the expected complexity is:

```text
Time:  O(V + E)
Space: O(V)
```

This makes the algorithm suitable for processing large sparse graphs.

The test cases also include isolated vertices, with each isolated vertex correctly treated as an individual connected component.

## Conclusion

This assignment implements three graph algorithms using the CSR graph infrastructure developed in Assignment 1:

- Triangle Counting identifies triangles in an undirected graph.
- Betweenness Centrality calculates vertex importance based on shortest paths.
- Connected Components identifies the different connected regions of an undirected graph.

The implementations were tested on graphs ranging from 10 to 100000 vertices. Smaller graphs were used for detailed correctness verification, while larger graphs were used to evaluate the scalability and execution performance of the algorithms.

Reusing the CSR representation provides a compact and efficient way to store sparse graphs and access their adjacency lists. Separating graph loading and CSR construction from algorithm execution also ensures that the reported execution times focus on the computational portion of each algorithm.

Overall, the assignment demonstrates the implementation and performance characteristics of different graph-processing techniques on graphs of varying sizes.
