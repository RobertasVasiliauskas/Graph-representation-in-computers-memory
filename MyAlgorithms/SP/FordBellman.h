#ifndef AIZO_2_WITH_STL_FORDBELLMAN_H
#define AIZO_2_WITH_STL_FORDBELLMAN_H

#include "../../Graph/Graph.h"

struct Edge {
    int source, destination, weight;
};

class FordBellman {
public:
    virtual void findShortestPathList(Graph &graph, int startVertex, int endVertex, bool writing);
    virtual void findShortestPathMatrix(Graph &graph, int startVertex, int endVertex, bool writing);
};


#endif //AIZO_2_WITH_STL_FORDBELLMAN_H
