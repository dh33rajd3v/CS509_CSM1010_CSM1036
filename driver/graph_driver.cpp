#include "../include/csr.h"

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

    return 0;
}