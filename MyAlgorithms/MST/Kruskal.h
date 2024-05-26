#ifndef AIZO_2_WITH_STL_KRUSKAL_H
#define AIZO_2_WITH_STL_KRUSKAL_H

#include <algorithm>
#include <numeric>
#include "../../Graph/Graph.h"
#include "../../Utilities/DisjointSet.h"


class Kruskal {
public:
    virtual void kruskalAlgorithm(Graph &graph, bool writing);
    virtual void kruskalAlgorithmMatrix(Graph &graph, bool writing);
private:
};


#endif //AIZO_2_WITH_STL_KRUSKAL_H
