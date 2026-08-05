#include "../include/sssp.h"

#include <queue>
#include <limits>
#include <functional>
#include <iomanip>

using namespace std;

void SSSP(
    const CSRGraph_withWeight& graph, int source)
{
    const int INFINITY = numeric_limits<int>::max();
    vector<int> distances(graph.vertices, INFINITY);

    using elements = pair<int, int>;

    priority_queue<elements, vector<elements>, greater<elements>> pq;

    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int distance_from_queue = pq.top().first;
        int vertex_from_queue = pq.top().second;

        pq.pop();

        if (distance_from_queue > distances[vertex_from_queue])
            continue;

        for (int i = graph.row_ptr[vertex_from_queue];
             i < graph.row_ptr[vertex_from_queue + 1];
             ++i)
        {
            int neighbour = graph.col_idx[i];
            int weight = graph.values[i];

            if (distances[vertex_from_queue] + weight <
                distances[neighbour])
            {
                distances[neighbour] =
                    distances[vertex_from_queue] + weight;

                pq.push(
                    {distances[neighbour], neighbour});
            }
        }
    }

    cout << "Algorithm: SSSP\n";
    cout << "Source: " << source << "\n\n";

    cout << left << setw(10) << "Vertex" << "Distance\n";

    for (int i = 0; i < graph.vertices; i++)
    {
        cout << left << setw(10) << i;

        if (distances[i] == INFINITY)
            cout << "not reachable\n";
        else
            cout << distances[i] << "\n";
    }
}