#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

#include "connected_components.h"
#include "csr.h"

using namespace std;

void run_connected_components()
{
    int source;

    CSRGraph graph =
        readGraph(
            "tests/connected_components/cc_100000.txt",
            source
        );

    vector<bool> visited(graph.vertices, false);
    vector<int> component(graph.vertices, -1);

    int component_count = 0;

    auto start = chrono::high_resolution_clock::now();

    for (int u = 0; u < graph.vertices; u++)
    {
        if (visited[u])
        {
            continue;
        }

        queue<int> q;

        visited[u] = true;
        component[u] = component_count;

        q.push(u);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int i = graph.row_ptr[current];
                 i < graph.row_ptr[current + 1];
                 i++)
            {
                int neighbour = graph.col_idx[i];

                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    component[neighbour] = component_count;

                    q.push(neighbour);
                }
            }
        }

        component_count++;
    }

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = end - start;

    cout << "Algorithm: Connected Components" << endl;

    cout << "Total components: "
         << component_count
         << endl;

    cout << "Vertex Component" << endl;

    for (int u = 0; u < graph.vertices; u++)
    {
        cout << u << " "
             << component[u]
             << endl;
    }

    cout << "Execution time: "
         << duration.count()
         << " ms"
         << endl;
}