#ifndef BFS_H
#define BFS_H

#include <vector>
#include "csr.h"

// struct CSR {
//     std::vector<int> row_ptr;
//     std::vector<int> col_idx;
//     std::vector<int> values;
// };

void BFS(const CSRGraph& graph, int source);

#endif