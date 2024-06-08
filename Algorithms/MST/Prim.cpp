#include "Prim.h"

void Prim::primAlgorithm(Graph &graph, bool writing) {
    int V = graph.numberOfVertices;

    std::vector<int> key(V, INT_MAX);
    std::vector<int> parent(V, -1);
    std::vector<bool> inMST(V, false);

    key[0] = 0;
    int totalWeight = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = -1;
        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = true;

        for (const auto &neighbor: graph.adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    if (writing) {
        std::cout << "Edges of Minimum Spanning Tree (Prim's Algorithm):\n";
        for (int i = 1; i < V; ++i) {
            totalWeight += key[i];
            std::cout << parent[i] << " - " << i << "\n";
        }
        std::cout << "Total weight of Minimum Spanning Tree: " << totalWeight << "\n";
    }
}

void Prim::primAlgorithmMatrix(Graph &graph, bool writing) {
    int V = graph.numberOfVertices;

    std::vector<int> key(V, INT_MAX);
    std::vector<int> parent(V, -1);
    std::vector<bool> inMST(V, false);

    key[0] = 0;

    int totalWeight = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = -1;
        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph.matrix[u][v] && !inMST[v] && graph.matrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph.matrix[u][v];
            }
        }
    }

    if (writing) {
        std::cout << "Edges of Minimum Spanning Tree (Prim's Algorithm - Matrix Representation):\n";
        for (int i = 1; i < V; ++i) {
            totalWeight += key[i];
            std::cout << parent[i] << " - " << i << "\n";
        }
        std::cout << "Total weight of Minimum Spanning Tree: " << totalWeight << "\n";
    }
}
