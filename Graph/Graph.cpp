#include "Graph.h"
#include "../Utilities/Utilities.h"

Graph::Graph() {
    isDirected = false;
    numberOfVertices = 0;
    numberOfEdges = 0;
    densityInPercent = 0;
    initializeConnections();
}

Graph::Graph(bool isDirected) {
    this->isDirected = isDirected;
    numberOfVertices = 0;
    numberOfEdges = 0;
    densityInPercent = 0;
    initializeConnections();
}

void Graph::initializeGraph(int vertices) {
    numberOfVertices = vertices;

    adjList.clear();
    adjList.resize(numberOfVertices);

    matrix = std::make_unique<std::unique_ptr<int[]>[]>(numberOfVertices);
    for (int i = 0; i < numberOfVertices; ++i) {
        matrix[i] = std::make_unique<int[]>(numberOfVertices);
        std::fill(matrix[i].get(), matrix[i].get() + numberOfVertices, 0);
    }

    connections.clear();
    initializeConnections();
}

void Graph::initializeConnections() {
    connections.resize(numberOfVertices, std::vector<bool>(numberOfVertices, true));
}


void Graph::addInitialEdges() {
    for (int i = 0; i < numberOfVertices - 1; ++i) {
        int value = Utilities::generateRandomNumber(1, 1000);

        adjList[i].emplace_back(i + 1, value);

        if (isDirected) {
            matrix[i][i + 1] = value;
            matrix[i + 1][i] = -value;
        } else {
            adjList[i + 1].emplace_back(i, value);
            matrix[i][i + 1] = value;
            matrix[i + 1][i] = value;
        }

        connections[i][i + 1] = false;
        connections[i + 1][i] = false;
    }

}

void Graph::addRandomEdges(int totalEdges) {
    int edgesAdded = 0;

    while (edgesAdded < totalEdges) {
        int vertexOne = Utilities::generateRandomNumber(0, numberOfVertices - 1);
        int vertexTwo = Utilities::generateRandomNumber(0, numberOfVertices - 1);
        int value = Utilities::generateRandomNumber(1, 1000);

        if (vertexOne != vertexTwo && connections[vertexOne][vertexTwo]) {
            adjList[vertexOne].emplace_back(vertexTwo, value);
            matrix[vertexOne][vertexTwo] = value;

            if (!isDirected) {
                adjList[vertexTwo].emplace_back(vertexOne, value);
                matrix[vertexTwo][vertexOne] = value;
            } else {
                matrix[vertexTwo][vertexOne] = -value;
            }

            connections[vertexOne][vertexTwo] = false;
            connections[vertexTwo][vertexOne] = false;
            ++edgesAdded;
        }
    }
}

void Graph::generateRandomGraph(int vertices, float density) {
    this->densityInPercent = density;
    initializeGraph(vertices);

    int maxEdges = isDirected ? numberOfVertices * (numberOfVertices - 1) : vertices * (vertices - 1) / 2;
    int edges = isDirected ? static_cast<int>((float)maxEdges * (density / 100 / 2)) :
                static_cast<int>((float)maxEdges * (density / 100));

    this->numberOfEdges = edges;

    addInitialEdges();
    addRandomEdges(edges - (numberOfVertices - 1));
}

void Graph::printList() const {
    for (int i = 0; i < numberOfVertices; ++i) {
        std::cout << i << " -> ";
        for (const auto& edge : adjList[i]) {
            std::cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        std::cout << std::endl;
    }
}

void Graph::printMatrix() const {
    std::cout << std::setw(6) << "   ";
    for (int j = 0; j < numberOfVertices; ++j) {
        std::cout << std::setw(5) << j << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < numberOfVertices; ++i) {
        std::cout << std::setw(5) << i << " ";
        for (int j = 0; j < numberOfVertices; ++j) {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::addEdge(int start, int end, int weight) {

    adjList[start].emplace_back(end, weight);
    matrix[start][end] = weight;

    if (!isDirected) {
        adjList[end].emplace_back(start, weight);
        matrix[end][start] = weight;
    } else {
        matrix[end][start] = -weight;
    }
}

float Graph::getDensityInPercent() const {
    return densityInPercent;
}

int Graph::getNumberOfVertices() const {
    return numberOfVertices;
}



