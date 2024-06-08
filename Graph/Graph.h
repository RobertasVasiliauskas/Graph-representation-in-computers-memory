#ifndef AIZO_2_WITH_STL_GRAPH_H
#define AIZO_2_WITH_STL_GRAPH_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

class Graph {

public:
    /**
     * Default constructor
     */
    Graph();

    /**
     * Constructor with argument to determine directed graph or not
     * @param isDirected argument to create a directed graph default false;
     */
    explicit Graph(bool isDirected);

    /**
     * Random graph generator
     * @param vertices number of vertices
     * @param density  density od the graph int number from 0 to 99
     */
    void generateRandomGraph(int vertices, float density);

    /**
     * Print graph as list
     */
    void printList() const;

    /**
     * Print graph as matrix
     */
    void printMatrix() const;

    /**
     * Adds egde to graph
     * @param start start vertex number
     * @param end  end vertex number
     * @param weight egde weight
     */
    void addEdge(int start, int end, int weight);

    /**
     * Initialization of graph
     * @param vertices number of vertices
     */
    void initializeGraph(int vertices);

    /**
     * Getter for density
     * @return density of graph
     */
    [[nodiscard]] float getDensityInPercent() const;

    /**
     * Getter for number of vertices
     * @return number of vertices in graph
     */
    [[nodiscard]] int getNumberOfVertices() const;

private:
    /**
     * Adds edges to speening graph
     */
    void addInitialEdges();

    /**
     * Adds random edges to graph
     * @param numberOfEdges number of edges to add
     */
    void addRandomEdges(int numberOfEdges);

    /**
     * Initialization of connections table for graph generation
     */
    void initializeConnections();

    /**
     * Generates full graph
     * @param vertices number of vertices
     * @param maxEdges number of maximus edges
     */
    void createFullGraph(int vertices, int maxEdges);

    /**
     * Picks random edge from graph for removal
     * @param edgesToRemove list of edges possible to remove
     */
    void removeRandomEdges(int edgesToRemove);

    /**
     * Removes edge from graph
     * @param vertexOne
     * @param vertexTwo
     */
    void removeEdge(int vertexOne, int vertexTwo);

    float densityInPercent;
    int numberOfVertices;
    [[maybe_unused]] int numberOfEdges;
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
