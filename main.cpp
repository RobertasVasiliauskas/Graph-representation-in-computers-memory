#include "Graph/Graph.h"
#include "Menu/Menu.h"
#include "Utilities/TimerDecorator.h"
#include "Utilities/Utilities.h"

int main() {

    std::string testing;
    bool test;
    int seriesCount = 100;

    std::cout << "Testing (yes, no) : ";
    std::cin >> testing;

    test = (testing == "yes");

    std::vector<int> density{25, 50, 99};
    std::vector<int> representativeValues{100, 200, 500, 1000, 2000, 5000, 10000};
    Graph graph = Graph(false);

    auto primPtr = std::make_unique<Prim>();
    auto primDecoratorPtr = std::make_unique<PrimDecorator>(std::move(primPtr));
    auto kruskalPtr = std::make_unique<Kruskal>();
    auto kruskalDecoratorPtr = std::make_unique<KruskalDecorator>(std::move(kruskalPtr));
    auto djistraPtr = std::make_unique<Djistra>();
    auto djistraDecoratorPtr = std::make_unique<DjistraDecorator>(std::move(djistraPtr));
    auto fordBellmanPtr = std::make_unique<FordBellman>();
    auto fordBellmanDecoratorPtr = std::make_unique<FordBellmanDecorator>(std::move(fordBellmanPtr));

    if (!test) {
        std::cout << std::endl;
        Menu menu;
        menu.show();
    } else {
        for (int representativeValue: representativeValues) {
            for (int j: density) {
                for (int k = 0; k < seriesCount; k++) {
                    graph.generateRandomGraph(representativeValue, (float) j);
                    primDecoratorPtr->primAlgorithm(graph, false);
                    primDecoratorPtr->primAlgorithmMatrix(graph, false);
                    kruskalDecoratorPtr->kruskalAlgorithm(graph, false);
                    kruskalDecoratorPtr->kruskalAlgorithmMatrix(graph, false);
                }
            }
        }

        graph = Graph(true);

        for (int representativeValue: representativeValues) {
            for (int j: density) {
                for (int k = 0; k < seriesCount; ++k) {
                    graph.generateRandomGraph(representativeValue, (float) j);

                    int startVertex = Utilities::generateRandomNumber(0, graph.getNumberOfVertices() - 1);
                    int endVertex = Utilities::generateRandomNumber(0, graph.getNumberOfVertices() - 1);

                    while (startVertex == endVertex) {
                        endVertex = Utilities::generateRandomNumber(0, graph.getNumberOfVertices() - 1);
                    }

                    djistraDecoratorPtr->findShortestPathList(graph, startVertex, endVertex, false);
                    djistraDecoratorPtr->findShortestPathMatrix(graph, startVertex, endVertex, false);
                    fordBellmanDecoratorPtr->findShortestPathList(graph, startVertex, endVertex, false);
                    fordBellmanDecoratorPtr->findShortestPathMatrix(graph, startVertex, endVertex, false);
                }
            }
        }
    }
}
