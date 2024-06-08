#ifndef AIZO_2_WITH_STL_DJISTRA_H
#define AIZO_2_WITH_STL_DJISTRA_H

#include "../../Graph/Graph.h"

class Djistra {
public:
    /**
     * Djistra algorithm for algorithm for undirected graphs represented as list
     * @param graph graph to calculate shortest path
     * @param startVertex start point
     * @param endVertex  end point
     * @param writing writing mode for GUI
     */
    virtual void findShortestPathList(Graph &graph, int startVertex, int endVertex, bool writing);

    /**
     * Djistra algorithm for algorithm for undirected graphs represented as incidence matrix
     * @param graph graph to calculate shortest path
     * @param startVertex start point
     * @param endVertex  end point
     * @param writing writing mode for GUI
     */
    virtual void findShortestPathMatrix(Graph &graph, int startVertex, int endVertex, bool writing);
};


#endif //AIZO_2_WITH_STL_DJISTRA_H
