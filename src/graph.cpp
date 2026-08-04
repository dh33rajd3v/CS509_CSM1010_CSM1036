#include "../include/graph.h"

Graph readGraph(
    const string& filename,
    int& source)
{
    ifstream inputFile(filename);

    cout << "Opening: " << filename << endl;

    if (!inputFile)
    {
        cerr << "Unable to open file.\n";
        exit(1);
    }

    Graph graph;

    inputFile >> graph.vertices >> graph.edges;

    graph.adjacencyList.resize(graph.vertices);

    for (int i = 0; i < graph.vertices; i++)
    {
        int vertex;
        int degree;

        inputFile >> vertex >> degree;

        for (int j = 0; j < degree; j++)
        {
            int neighbour;

            inputFile >> neighbour;

            graph.adjacencyList[vertex].push_back(
                neighbour
            );
        }
    }

    string sourceLabel;

    inputFile >> sourceLabel >> source;

    inputFile.close();

    return graph;
}

void printGraph(
    const Graph& graph)
{
    cout << "\nAdjacency List\n\n";

    for (int i = 0; i < graph.vertices; i++)
    {
        cout << i << " -> ";

        for (int neighbour :
             graph.adjacencyList[i])
        {
            cout << neighbour << " ";
        }

        cout << endl;
    }
}