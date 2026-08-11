#include <iostream>
#include "../include/triangle_counting.h"
#include "../include/betweenness_centrality.h"

#include "csr.h"

using namespace std;

int main()
{
    cout << "CSR infrastructure connected successfully." << endl;

    cout << "\n 1. Triangle Counting Problem\n 2. Betweenness Centrality Problem\n\n" << endl;
    int choice;
    cin>>choice;

    switch (choice)
    {
    case 1:
        run_triangle();
        break;

    case 2:
        betweennessCentrality();
        break;
    
    default:
        break;
    }

    return 0;
}