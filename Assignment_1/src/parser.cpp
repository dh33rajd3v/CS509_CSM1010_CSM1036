#include "../include/parser.h"
#include "../include/csr.h"
#include "../include/bfs.h"
#include "../include/sssp.h"
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

void run_SSSP()
{
    int source;

    CSRGraph_withWeight graph =
        readGraph_withWeight(
            "tests/sssp_tests/sssp_10.txt",
            source
        );

    printCSR_withWeight(graph);

    SSSP(graph, source);
}