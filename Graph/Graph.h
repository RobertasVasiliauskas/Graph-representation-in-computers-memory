#ifndef AIZO_2_WITH_STL_GRAPH_H
#define AIZO_2_WITH_STL_GRAPH_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

class Graph {

public:
    Graph();
    explicit Graph(bool isDirected);
    void generateRandomGraph(int vertices, float density);
    void printList() const;
    void printMatrix() const;
    void addEdge(int start, int end, int weight);
    void initializeGraph(int vertices);

    float getDensityInPercent() const;

    int getNumberOfVertices() const;

private:

    void addInitialEdges();
    void addRandomEdges(int numberOfEdges);
    void initializeConnections();

    float densityInPercent;
    int numberOfVertices;
    int numberOfEdges;
    bool isDirected;
    std::vector<std::vector<std::pair<int, int>>> adjList;
    std::unique_ptr<std::unique_ptr<int[]>[]> matrix;
    std::vector<std::vector<bool>> connections;

    friend class Prim;
    friend class Kruskal;
    friend class Djistra;
    friend class FordBellman;
};


#endif //AIZO_2_WITH_STL_GRAPH_H
