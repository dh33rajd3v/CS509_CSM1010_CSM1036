#include <iostream>
#include "../include/triangle_counting.h"
#include "../include/betweenness_centrality.h"
#include "../include/graph_driver.h"
#include "../include/connected_components.h"

#include "../../Assignment_1/include/csr.h"

using namespace std;

void assignment_2_func()
{
    // cout << "CSR infrastructure connected successfully." << endl;

    cout << "\n 1. Triangle Counting Problem"
         << "\n 2. Betweenness Centrality Problem"
         << "\n 3. Connected Components Problem"
         << "\n\n Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        run_triangle();
        break;

    case 2:
        betweennessCentrality();
        break;

    case 3:
        run_connected_components();
        break;

    default:
        cout << "Invalid choice." << endl;
        break;
    }
}