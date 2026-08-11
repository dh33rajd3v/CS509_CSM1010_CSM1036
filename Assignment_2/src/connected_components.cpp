#include "../include/connected_components.h"
#include <filesystem>

#include "../../Assignment_1/include/csr.h"

using namespace std;

void run_connected_components()
{
    int source;

    const string directory = "Assignment_2/tests/connected_components";

    vector<string> files;

    for (const auto& entry : filesystem::directory_iterator(directory))
    {
        if (entry.is_regular_file())
        {
            files.push_back(entry.path().filename().string());
        }
    }

    if (files.empty())
    {
        cerr << "No files found in " << directory << endl;
        return;
    }

    sort(files.begin(), files.end());

    cout << "\nSelect a graph file:\n";

    for (size_t i = 0; i < files.size(); ++i)
    {
        cout << i + 1 << ". " << files[i] << '\n';
    }

    int choice;

    cout << "\n\nEnter choice: ";
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(files.size()))
    {
        cerr << "Invalid choice.\n";
        return;
    }

    string selected_file =
        directory + "/" + files[choice - 1];

    CSRGraph graph =
        readGraph(
            selected_file,
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