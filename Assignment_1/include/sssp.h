#ifndef SSSP_HPP
#define SSSP_HPP

#include <vector>
#include "csr.h"

void SSSP(
    const CSRGraph_withWeight& graph,
    int source);

#endif