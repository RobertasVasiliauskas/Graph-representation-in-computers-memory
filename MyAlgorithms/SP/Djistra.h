#ifndef AIZO_2_WITH_STL_DJISTRA_H
#define AIZO_2_WITH_STL_DJISTRA_H

#include "../../Graph/Graph.h"

class Djistra {
public:
    virtual void findShortestPathList(Graph &graph, int startVertex, int endVertex, bool writing);
    virtual void findShortestPathMatrix(Graph &graph, int startVertex, int endVertex, bool writing);
};


#endif //AIZO_2_WITH_STL_DJISTRA_H
