#ifndef AIZO_2_WITH_STL_PRIM_H
#define AIZO_2_WITH_STL_PRIM_H

#include <iostream>
#include <vector>
#include <climits>
#include "../../Graph/Graph.h"

class Prim{
public:
    virtual void primAlgorithm(Graph &graph, bool writing);
    virtual void primAlgorithmMatrix(Graph &graph, bool writting);
private:
};


#endif //AIZO_2_WITH_STL_PRIM_H
