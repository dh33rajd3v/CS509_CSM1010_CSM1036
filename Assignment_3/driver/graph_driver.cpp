#include <iostream>
#include "../include/gradient_descent.h"
#include "../include/maxflow.h"
#include "../include/graph_driver.h"
#include "../../Assignment_1/include/csr.h"

using namespace std;

void assignment_3_func()
{
    cout << "\n 1. Gradient Descent"
         << "\n 2. Maxflow-Mincut"
         << "\n\n Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        gd_func();
        break;

    case 2:
        mm_fn();

    default:
        cout << "Invalid choice." << endl;
        break;
    }
}