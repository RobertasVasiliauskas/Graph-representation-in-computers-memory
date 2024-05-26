#include <queue>
#include <limits>
#include <algorithm>
#include "Djistra.h"

void Djistra::findShortestPathList(Graph &graph, int startVertex, int endVertex, bool writing) {
    int V = graph.numberOfVertices;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    std::vector<int> dist(V, std::numeric_limits<int>::max());
    std::vector<int> prev(V, -1);  // To store the path

    pq.emplace(0, startVertex);
    dist[startVertex] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == endVertex) break;  // Stop if we reached the end vertex

        for (const auto &neighbor: graph.adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
                prev[v] = u;
            }
        }
    }

    if (writing) {
        std::cout << "Vertex Distance from " << startVertex << " to " << endVertex << " (Adjacency List): "
                  << dist[endVertex] << "\n";

        if (dist[endVertex] != std::numeric_limits<int>::max()) {
            std::vector<int> path;
            for (int at = endVertex; at != -1; at = prev[at])
                path.push_back(at);
            std::reverse(path.begin(), path.end());

            std::cout << "Path: ";
            for (size_t i = 0; i < path.size(); ++i) {
                if (i > 0) std::cout << " -> ";
                std::cout << path[i];
            }
            std::cout << "\n";
        }
    }
}

void Djistra::findShortestPathMatrix(Graph &graph, int startVertex, int endVertex, bool writing) {
    int V = graph.numberOfVertices;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    std::vector<int> dist(V, std::numeric_limits<int>::max());
    std::vector<int> prev(V, -1);

    pq.emplace(0, startVertex);
    dist[startVertex] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == endVertex) break;

        for (int v = 0; v < V; ++v) {
            if (graph.matrix[u][v] > 0) {
                int weight = graph.matrix[u][v];

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.emplace(dist[v], v);
                    prev[v] = u;
                }
            }
        }
    }

    if (writing) {
        std::cout << "Vertex Distance from " << startVertex << " to " << endVertex << " (Incidence Matrix): "
                  << dist[endVertex] << "\n";

        if (dist[endVertex] != std::numeric_limits<int>::max()) {
            std::vector<int> path;
            for (int at = endVertex; at != -1; at = prev[at])
                path.push_back(at);
            std::reverse(path.begin(), path.end());

            std::cout << "Path: ";
            for (size_t i = 0; i < path.size(); ++i) {
                if (i > 0) std::cout << " -> ";
                std::cout << path[i];
            }
            std::cout << "\n";
        }
    }
}
