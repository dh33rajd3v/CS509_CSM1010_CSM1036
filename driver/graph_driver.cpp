#include "../include/csr.h"
#include "../include/bfs.h"

int main()
{
    int source;

    CSRGraph graph =
        readGraph(
            "tests/bfs_10.txt",
            source
        );

    printCSR(graph);

    cout << "\nSource vertex: "
         << source
         << endl;

    BFS(graph, source);

    

    return 0;
}