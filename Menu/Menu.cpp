#include "Menu.h"
#include "../Graph/Graph.h"
#include "../Utilities/TimerDecorator.h"

void Menu::show() {
    const std::vector<std::string> menuOptions = {
            "Minimal spanning tree algorithms",
            "Shortest path in graph algorithms",
            "Exit program"
    };

    while (chooseSubMenu != 3) {
        for (size_t i = 0; i < menuOptions.size(); ++i) {
            std::cout << i + 1 << ". " << menuOptions[i] << std::endl;
        }
        std::cout << std::endl;

        std::cout << ">>";
        std::cin >> chooseSubMenu;
        std::cout << std::endl;

        if (chooseSubMenu >= 1 && chooseSubMenu <= menuOptions.size()) {
            switch (chooseSubMenu) {
                case 1:
                    graph = Graph(false);
                    showFirstLayer();
                    subMenuNumber = 0;
                    break;
                case 2:
                    graph = Graph(true);
                    showSecondLayer();
                    subMenuNumber = 0;
                    break;
                case 3:
                    std::cout << std::endl;
                    break;
            }
        } else {
            std::cout << "Error: Please re-enter your choice" << std::endl;
        }
    }
}

void Menu::showFirstLayer() {
    const std::vector<std::string> firstLayerMenuOptions = {
            "Load data from file",
            "Generate a random graph",
            "Display the graph",
            "Prim's algorithm",
            "Kruskal's algorithm",
            "Exit program"
    };

    while (subMenuNumber != 6) {

        for (size_t i = 0; i < firstLayerMenuOptions.size(); ++i) {
            std::cout << i + 1 << ". " << firstLayerMenuOptions[i] << std::endl;
        }
        std::cout << std::endl;

        std::cout << ">> ";
        std::cin >> subMenuNumber;

        if (subMenuNumber >= 1 && subMenuNumber <= firstLayerMenuOptions.size()) {
            switch (subMenuNumber) {
                case 1: {
                    std::cout << "Enter file name: ";
                    std::cin >> filename;
                    std::ifstream file(filename);

                    file >> temp[0];
                    file >> temp[1];

                    graph.initializeGraph(temp[1]);

                    for (int i = 0; i < temp[0]; i++) {
                        file >> temp[2] >> temp[3] >> temp[4];
                        std::cout << temp[2] << temp[3] << temp[4] << std::endl;
                        graph.addEdge(temp[2], temp[3], temp[4]);
                    }

                    file.close();
                    break;
                }
                case 2:
                    std::cout << std::endl;
                    std::cout << "Enter number of vertices: ";
                    std::cin >> temp[0];
                    std::cout << "Enter density of graph in % : ";
                    std::cin >> temp[1];
                    std::cout << std::endl;
                    graph.generateRandomGraph(temp[0], temp[1]);
                    break;
                case 3:
                    std::cout << std::endl;
                    graph.printList();
                    graph.printMatrix();
                    std::cout << std::endl;
                    break;
                case 4: {

                    auto primPtr = std::make_unique<Prim>();
                    auto primDecoratorPtr = std::make_unique<PrimDecorator>(std::move(primPtr));

                    std::cout << std::endl;

                    primDecoratorPtr->primAlgorithm(graph, true);

                    std::cout << std::endl;

                    primDecoratorPtr->primAlgorithmMatrix(graph, true);

                    std::cout << std::endl;

                    break;
                }
                case 5: {
                    auto kruskalPtr = std::make_unique<Kruskal>();
                    auto kruskalDecoratorPtr = std::make_unique<KruskalDecorator>(std::move(kruskalPtr));

                    std::cout << std::endl;

                    kruskalDecoratorPtr->kruskalAlgorithm(graph, true);

                    std::cout << std::endl;

                    kruskalDecoratorPtr->kruskalAlgorithmMatrix(graph, true);

                    std::cout << std::endl;

                    break;
                }
                case 6:
                    std::cout << std::endl;
                    break;
            }
        } else {
            std::cout << "Error: Please re-enter your choice" << std::endl;
        }
    }
}

void Menu::showSecondLayer() {
    const std::vector<std::string> secondLayerMenuOptions = {
            "Load data from file",
            "Generate a random graph",
            "Display the graph",
            "Dijkstra's algorithm",
            "Bellman-Ford algorithm",
            "Exit program"
    };

    while (subMenuNumber != 6) {

        for (size_t i = 0; i < secondLayerMenuOptions.size(); ++i) {
            std::cout << i + 1 << ". " << secondLayerMenuOptions[i] << std::endl;
        }
        std::cout << std::endl;

        std::cout << ">> ";
        std::cin >> subMenuNumber;
        std::cout << std::endl;

        if (subMenuNumber >= 1 && subMenuNumber <= secondLayerMenuOptions.size()) {
            switch (subMenuNumber) {
                case 1: {
                    std::cout << "Enter file name: ";
                    std::cin >> filename;
                    std::ifstream file(filename);

                    file >> temp[0];
                    file >> temp[1];

                    for (int i = 0; i < temp[0]; i++) {
                        for (int j = 0; i < temp[1]; j++) {
                            file >> temp[2] >> temp[3] >> temp[4];
                            graph.addEdge(temp[2], temp[3], temp[4]);
                        }
                    }

                    file.close();
                    break;
                }
                case 2:
                    std::cout << std::endl;
                    std::cout << "Enter number of vertices: ";
                    std::cin >> temp[0];
                    std::cout << "Enter density of graph in % : ";
                    std::cin >> temp[1];
                    std::cout << std::endl;
                    graph.generateRandomGraph(temp[0], temp[1]);
                    std::cout << std::endl;
                    break;
                case 3:
                    std::cout << std::endl;
                    graph.printList();
                    std::cout << std::endl;
                    graph.printMatrix();
                    std::cout << std::endl;
                    break;
                case 4: {
                    auto djistraPtr = std::make_unique<Djistra>();
                    auto djistraDecoratorPtr = std::make_unique<DjistraDecorator>(std::move(djistraPtr));

                    std::cout << std::endl;
                    std::cout << "Enter start vertex: ";
                    std::cin >> temp[0];
                    std::cout << "Enter end vertex: ";
                    std::cin >> temp[1];
                    std::cout << std::endl;
                    djistraDecoratorPtr->findShortestPathList(graph, temp[0], temp[1], true);
                    std::cout << std::endl;
                    djistraDecoratorPtr->findShortestPathMatrix(graph, temp[0], temp[1], true);
                    std::cout << std::endl;
                    break;
                }
                case 5: {

                    auto fordBellmanPtr = std::make_unique<FordBellman>();
                    auto fordBellmanDecoratorPtr = std::make_unique<FordBellmanDecorator>(std::move(fordBellmanPtr));

                    std::cout << std::endl;
                    std::cout << "Enter start vertex: ";
                    std::cin >> temp[0];
                    std::cout << "Enter end vertex: ";
                    std::cin >> temp[1];
                    std::cout << std::endl;
                    fordBellmanDecoratorPtr->findShortestPathList(graph, temp[0], temp[1], true);
                    std::cout << std::endl;
                    fordBellmanDecoratorPtr->findShortestPathMatrix(graph, temp[0], temp[1], true);
                    std::cout << std::endl;
                    break;
                }
                case 6:
                    // Exit program
                    std::cout << std::endl;
                    break;
            }
        } else {
            std::cout << "Error: Please re-enter your choice" << std::endl;
        }
    }
}
