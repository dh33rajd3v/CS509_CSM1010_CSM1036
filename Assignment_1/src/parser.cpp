#include "../include/parser.h"
#include "../include/csr.h"
#include "../include/bfs.h"
#include "../include/dfs.h"

void run_BFS()
{
    int source;

    CSRGraph graph =
        readGraph(
            "tests/bfs_10.txt",
            source
        );

    printCSR(graph);

    BFS(graph, source);
}

void run_DFS()
{
    int source;

    CSRGraph graph =
        readGraph(
            "tests/bfs_10.txt",
            source
        );

    printCSR(graph);

    DFS(graph, source);
}