#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <iostream>
#include <string>

#include "csr.h"

CSRGraph readGraph(
    const string& filename,
    int& source
);

void printCSR(
    const CSRGraph& graph
);

#endif