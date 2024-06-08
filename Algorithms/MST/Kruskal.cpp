#include "Kruskal.h"

void Kruskal::kruskalAlgorithm(Graph &graph, bool writing) {
    int V = graph.numberOfVertices;

    std::vector<std::pair<int, std::pair<int, int>>> edges;

    for (int u = 0; u < V; ++u) {
        for (const auto &neighbor: graph.adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            edges.push_back({weight, {u, v}});
        }
    }

    std::sort(edges.begin(), edges.end());

    DisjointSet ds(V);

    std::vector<std::pair<int, int>> resultMST;
    int totalWeight = 0;

    for (const auto &edge: edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int weight = edge.first;
        int setU = ds.find(u);
        int setV = ds.find(v);
        if (setU != setV) {
            resultMST.emplace_back(u, v);
            ds.Union(setU, setV);
            totalWeight += weight;
        }
    }

    if (writing) {
        std::cout << "Edges of Minimum Spanning Tree (Kruskal's Algorithm - Adjacency List Representation):\n";
        for (const auto &edge: resultMST) {
            std::cout << edge.first << " - " << edge.second << "\n";
        }
        std::cout << "Total weight of Minimum Spanning Tree: " << totalWeight << "\n";
    }
}

void Kruskal::kruskalAlgorithmMatrix(Graph &graph, bool writing) {
    int V = graph.numberOfVertices;

    std::vector<std::pair<int, std::pair<int, int>>> edges;

    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            if (graph.matrix[u][v] != 0) {
                edges.push_back({graph.matrix[u][v], {u, v}});
            }
        }
    }

    std::sort(edges.begin(), edges.end());

    DisjointSet ds(V);

    std::vector<std::pair<int, int>> resultMST;
    int totalWeight = 0;

    for (const auto &edge: edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int weight = edge.first;
        int setU = ds.find(u);
        int setV = ds.find(v);
        if (setU != setV) {
            resultMST.emplace_back(u, v);
            ds.Union(setU, setV);
            totalWeight += weight;
        }
    }

    if (writing) {
        std::cout << "Edges of Minimum Spanning Tree (Kruskal's Algorithm - Adjacency Matrix Representation):\n";
        for (const auto &edge: resultMST) {
            std::cout << edge.first << " - " << edge.second << "\n";
        }
        std::cout << "Total weight of Minimum Spanning Tree: " << totalWeight << "\n";
    }
}
