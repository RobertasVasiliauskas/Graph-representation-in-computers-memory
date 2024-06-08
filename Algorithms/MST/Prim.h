#ifndef AIZO_2_WITH_STL_PRIM_H
#define AIZO_2_WITH_STL_PRIM_H

#include <iostream>
#include <vector>
#include <climits>
#include "../../Graph/Graph.h"

class Prim {
public:
    /**
     * Prim algorithm for undirected graphs represented as list
     * @param graph graph to run algorithm on it
     * @param writing writing mode for gui
     */
    virtual void primAlgorithm(Graph &graph, bool writing);

    /**
     * Prim algorithm for undirected graphs represented as incidence matrix
     * @param graph graph to run algorithm on it
     * @param writing writing mode for gui
     */
    virtual void primAlgorithmMatrix(Graph &graph, bool writing);

private:
};


#endif //AIZO_2_WITH_STL_PRIM_H
