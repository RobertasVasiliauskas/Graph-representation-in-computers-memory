#include "Graph/Graph.h"
#include "Menu/Menu.h"
#include "Utilities/TimerDecorator.h"
#include "Utilities/Utilities.h"

template <typename Algorithm, typename Decorator>
std::unique_ptr<Decorator> createDecorator() {
    auto algorithmPtr = std::make_unique<Algorithm>();
    return std::make_unique<Decorator>(std::move(algorithmPtr));
}

void runMSTAlgorithms(Graph &graph, const std::vector<int> &densities, const std::vector<int> &representativeValues,
                      int seriesCount,
                      PrimDecorator &primDecorator, KruskalDecorator &kruskalDecorator) {
    for (int representativeValue: representativeValues) {
        for (int density: densities) {
            for (int i = 0; i < seriesCount; ++i) {
                graph.generateRandomGraph(representativeValue, static_cast<float>(density));
                primDecorator.primAlgorithm(graph, false);
                primDecorator.primAlgorithmMatrix(graph, false);
                kruskalDecorator.kruskalAlgorithm(graph, false);
                kruskalDecorator.kruskalAlgorithmMatrix(graph, false);
            }
        }
        std::cout << "Completed for: " << representativeValue << std::endl;
    }
}

void
runShortestPathAlgorithms(Graph &graph, const std::vector<int> &densities, const std::vector<int> &representativeValues,
                          int seriesCount,
                          DjistraDecorator &dijkstraDecorator, FordBellmanDecorator &fordBellmanDecorator) {
    for (int representativeValue: representativeValues) {
        for (int density: densities) {
            for (int i = 0; i < seriesCount; ++i) {
                graph.generateRandomGraph(representativeValue, static_cast<float>(density));
                int startVertex = Utilities::generateRandomNumber(0, graph.getNumberOfVertices() - 1);
                int endVertex = Utilities::generateRandomNumber(0, graph.getNumberOfVertices() - 1);

                while (startVertex == endVertex) {
                    endVertex = Utilities::generateRandomNumber(0, graph.getNumberOfVertices() - 1);
                }

                dijkstraDecorator.findShortestPathList(graph, startVertex, endVertex, false);
                dijkstraDecorator.findShortestPathMatrix(graph, startVertex, endVertex, false);
                fordBellmanDecorator.findShortestPathList(graph, startVertex, endVertex, false);
                fordBellmanDecorator.findShortestPathMatrix(graph, startVertex, endVertex, false);
            }
        }
        std::cout << "Completed for: " << representativeValue << std::endl;
    }
}

int main() {
    std::string testingInput;
    bool isTesting;
    const int seriesCount = 100;

    std::cout << "Testing (yes, no) : ";
    std::cin >> testingInput;

    isTesting = (testingInput == "yes");

    std::vector<int> densities{25, 50, 99};
    std::vector<int> representativeValues{10, 20, 50, 100, 200, 500, 1000};

    Graph undirectedGraph(false);

    auto primDecoratorPtr = createDecorator<Prim, PrimDecorator>();
    auto kruskalDecoratorPtr = createDecorator<Kruskal, KruskalDecorator>();
    auto dijkstraDecoratorPtr = createDecorator<Djistra, DjistraDecorator>();
    auto fordBellmanDecoratorPtr = createDecorator<FordBellman, FordBellmanDecorator>();

    if (!isTesting) {
        std::cout << std::endl;
        Menu menu;
        menu.show();
    } else {
        runMSTAlgorithms(undirectedGraph, densities, representativeValues, seriesCount, *primDecoratorPtr,
                         *kruskalDecoratorPtr);

        Graph directedGraph(true);
        runShortestPathAlgorithms(directedGraph, densities, representativeValues, seriesCount, *dijkstraDecoratorPtr,
                                  *fordBellmanDecoratorPtr);
    }

    return 0;
}
