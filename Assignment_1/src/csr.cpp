#include "../include/csr.h"

CSRGraph readGraph(
    const string& filename,
    int& source)
{
    ifstream inputFile(filename);

    if (!inputFile)
    {
        cerr << "Unable to open file.\n";
        exit(1);
    }

    CSRGraph graph;

    inputFile >> graph.vertices
              >> graph.edges;

    graph.row_ptr.push_back(0);

    for (int i = 0; i < graph.vertices; i++)
    {
        int vertex;
        int degree;

        inputFile >> vertex >> degree;

        for (int j = 0; j < degree; j++)
        {
            int neighbour;

            inputFile >> neighbour;

            graph.col_idx.push_back(
                neighbour
            );
        }

        graph.row_ptr.push_back(
            graph.col_idx.size()
        );
    }

    string label;

    inputFile >> label >> source;

    inputFile.close();

    return graph;
}

CSRGraph_withWeight readGraph_withWeight(
    const string& filename,
    int& source)
{
    ifstream inputFile(filename);

    if (!inputFile)
    {
        cerr << "Unable to open file.\n";
        exit(1);
    }

    CSRGraph_withWeight graph;

    inputFile >> graph.vertices
              >> graph.edges;

    graph.row_ptr.push_back(0);

    for (int i = 0; i < graph.vertices; i++)
    {
        int vertex;
        int degree;
        int weight;

        inputFile >> vertex >> degree;

        for (int j = 0; j < degree; j++)
        {
            int neighbour;

            inputFile >> neighbour >> weight;

            graph.col_idx.push_back(
                neighbour
            );

            graph.values.push_back(
                weight
            );
        }

        graph.row_ptr.push_back(
            graph.col_idx.size()
        );
    }

    string label;

    inputFile >> label >> source;

    inputFile.close();

    return graph;
}


void printCSR(
    const CSRGraph& graph)
{
    cout << "\nrow_ptr:\n";

    for (int value : graph.row_ptr)
    {
        cout << value << " ";
    }

    cout << "\n\ncol_idx:\n";

    for (int value : graph.col_idx)
    {
        cout << value << " ";
    }

    cout << endl;
}


void printCSR_withWeight(
    const CSRGraph_withWeight& graph)
{
    cout << "\nrow_ptr:\n";

    for (int value : graph.row_ptr)
    {
        cout << value << " ";
    }

    cout << "\n\ncol_idx:\n";

    for (int value : graph.col_idx)
    {
        cout << value << " ";
    }

    cout << endl;
}