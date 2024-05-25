#include "Graph.h"
#include "../Utilities/Utilities.h"

Graph::Graph(bool isDirected) {
    this->isDirected = isDirected;
    numberOfVertices = 0;
}

Graph::Graph() {
    isDirected = false;
    numberOfVertices = 0;
}

void Graph::generateRandomGraph(int vertices, float densityInPercent) {
    numberOfVertices = vertices;

    bool connections[numberOfVertices][numberOfVertices];
    int maxEdges, numberOfEdges;

    maxEdges = isDirected ? numberOfVertices * (numberOfVertices - 1) : vertices * (vertices - 1) / 2;
    numberOfEdges = static_cast<int>((float) maxEdges * (densityInPercent / 100));

    adjList.clear();
    adjList.resize(numberOfVertices);
    matrix.reset();

    for (int i = 0; i <= numberOfVertices - 1; i++) {
        for (int j = 0; j <= numberOfVertices - 1; j++) {
            connections[i][j] = true;
        }
    }

    matrix = std::make_unique<std::unique_ptr<int[]>[]>(numberOfVertices);
    for (int i = 0; i < numberOfVertices; ++i) {
        matrix[i] = std::make_unique<int[]>(numberOfVertices);
    }

    for (int i = 0; i < numberOfVertices - 1; ++i) {
        if (isDirected) {
            int value = Utilities::generateRandomNumber(1, 10);

            adjList[i].emplace_back(i + 1, value);

            matrix[i][i] = value;
            matrix[i][i + 1] = (-1 * value);

            connections[i][i] = false;
            connections[i][i + 1] = false;
        } else {
            int value = Utilities::generateRandomNumber(1, 10);

            adjList[i].emplace_back(i + 1, value);
            adjList[i + 1].emplace_back(i, value);

            matrix[i][i] = value;
            matrix[i][i + 1] = value;

            connections[i][i] = false;
            connections[i][i + 1] = false;
        }
    }

    for (int i = 0; i < numberOfEdges - (numberOfVertices - 1); ++i) {

        std::cout << i << " " << numberOfEdges - (numberOfVertices - 1) << std::endl;

        int vertexOne = Utilities::generateRandomNumber(0, numberOfVertices - 1);
        int vertexTwo = Utilities::generateRandomNumber(0, numberOfVertices - 1);
        int value = Utilities::generateRandomNumber(1, 10);

        if (isDirected) {
            if (connections[vertexOne][vertexTwo]) {
                adjList[vertexOne].emplace_back(vertexTwo, value);

                matrix[vertexOne][vertexTwo] = value;
                matrix[vertexTwo][vertexOne] = (-1 * value);

                connections[vertexOne][vertexTwo] = false;
                connections[vertexTwo][vertexOne] = false;

            } else {
                --i;
            }
        } else {
            if (connections[vertexOne][vertexTwo]) {
                adjList[vertexOne].emplace_back(vertexTwo, value);
                adjList[vertexTwo].emplace_back(vertexOne, value);

                matrix[vertexOne][vertexTwo] = value;
                matrix[vertexTwo][vertexOne] = value;

                connections[vertexOne][vertexTwo] = false;
                connections[vertexTwo][vertexOne] = false;

            } else {
                --i;
            }
        }
    }
}
