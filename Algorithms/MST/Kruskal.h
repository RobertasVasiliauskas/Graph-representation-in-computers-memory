#ifndef AIZO_2_WITH_STL_KRUSKAL_H
#define AIZO_2_WITH_STL_KRUSKAL_H

#include <algorithm>
#include <numeric>
#include "../../Graph/Graph.h"
#include "../../Utilities/DisjointSet.h"


class Kruskal {
public:
    /**
     * Kruskal algorithm for undirected graphs represented as list
     * @param graph graph to run algorithm on it
     * @param writing writing mode for gui
     */
    virtual void kruskalAlgorithm(Graph &graph, bool writing);

    /**
     * Kruskal algorithm for undirected graphs represented as incidence matrix
     * @param graph graph to run algorithm on it
     * @param writing writing mode for gui
     */
    virtual void kruskalAlgorithmMatrix(Graph &graph, bool writing);

private:
};


#endif //AIZO_2_WITH_STL_KRUSKAL_H
