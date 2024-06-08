#ifndef AIZO_2_WITH_STL_FORDBELLMAN_H
#define AIZO_2_WITH_STL_FORDBELLMAN_H

#include "../../Graph/Graph.h"

class FordBellman {
public:
    /**
     * Ford-Bellman algorithm for algorithm for undirected graphs represented as list
     * @param graph graph to calculate shortest path
     * @param startVertex start point
     * @param endVertex  end point
     * @param writing writing mode for GUI
     */
    virtual void findShortestPathList(Graph &graph, int startVertex, int endVertex, bool writing);

    /**
     * Ford-Bellman algorithm for algorithm for undirected graphs represented as incidence matrix
     * @param graph graph to calculate shortest path
     * @param startVertex start point
     * @param endVertex  end point
     * @param writing writing mode for GUI
     */
    virtual void findShortestPathMatrix(Graph &graph, int startVertex, int endVertex, bool writing);
};


#endif //AIZO_2_WITH_STL_FORDBELLMAN_H
