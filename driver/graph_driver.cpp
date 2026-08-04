#include "../include/graph.h"

int main()
{
    int source;

    Graph graph =
        readGraph(
            "tests/bfs_10.txt",
            source
        );

    printGraph(graph);

    cout << "\nSource vertex: "
         << source
         << endl;

    return 0;
}