#ifndef AIZO_2_WITH_STL_GRAPH_H
#define AIZO_2_WITH_STL_GRAPH_H

#include <iostream>
#include <vector>
#include <memory>

class Graph {
public:
    Graph(bool isDirected);
    Graph();
    void generateRandomGraph(int vertices, float densityInPercent);

private:

    bool isDirected;
    int numberOfVertices;

    std::vector<std::vector<std::pair<int, int>>> adjList;
    std::unique_ptr<std::unique_ptr<int[]>[]> matrix;

};


#endif //AIZO_2_WITH_STL_GRAPH_H
