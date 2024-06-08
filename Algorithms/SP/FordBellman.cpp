#include <stack>
#include <limits>
#include "FordBellman.h"

void FordBellman::findShortestPathList(Graph &graph, int startVertex, int endVertex, bool writing) {
    int V = graph.numberOfVertices;
    std::vector<int> distance(V, INT_MAX);
    std::vector<int> predecessor(V, -1);

    distance[startVertex] = 0;

    for (int i = 1; i <= V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (const auto &neighbor: graph.adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    predecessor[v] = u;
                }
            }
        }
    }

    std::stack<int> path;
    for (int at = endVertex; at != -1; at = predecessor[at]) {
        path.push(at);
    }


    if (writing) {
        if (distance[endVertex] != std::numeric_limits<int>::max()) {
            std::cout << "Vertex distance from " << startVertex << " to " << endVertex << " (Adjacency List): "
                      << distance[endVertex] << "\nPath: ";
            while (!path.empty()) {
                if (path.size() > 1) {
                    std::cout << path.top() << " -> ";
                } else {
                    std::cout << path.top();
                }
                path.pop();
            }
            std::cout << "\n";
        } else {
            std::cout << "Path not specified" << std::endl;
        }
    }
}

void FordBellman::findShortestPathMatrix(Graph &graph, int startVertex, int endVertex, bool writing) {
    int V = graph.numberOfVertices;
    std::vector<int> distance(V, INT_MAX);
    std::vector<int> predecessor(V, -1);

    distance[startVertex] = 0;

    for (int i = 1; i <= graph.numberOfVertices - 1; ++i) {
        for (int u = 0; u < graph.numberOfVertices; ++u) {
            for (int v = 0; v < graph.numberOfVertices; ++v) {
                if (graph.matrix[u][v] > 0) {
                    int weight = graph.matrix[u][v];
                    if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                        distance[v] = distance[u] + weight;
                        predecessor[v] = u;
                    }
                }
            }
        }
    }

    std::stack<int> path;
    for (int at = endVertex; at != -1; at = predecessor[at]) {
        path.push(at);
    }

    if (writing) {
        if (distance[endVertex] != std::numeric_limits<int>::max()) {
            std::cout << "Vertex distance from " << startVertex << " to " << endVertex << " (Incidence matrix): "
                      << distance[endVertex] << "\nPath: ";
            while (!path.empty()) {
                if (path.size() > 1) {
                    std::cout << path.top() << " -> ";
                } else {
                    std::cout << path.top();
                }
                path.pop();
            }
            std::cout << "\n";
        } else {
            std::cout << "Path not specified" << std::endl;
        }
    }
}
