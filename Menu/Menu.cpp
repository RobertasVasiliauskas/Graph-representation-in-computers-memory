#include "Menu.h"

void Menu::show() {
    const std::vector<std::string> mainMenuOptions = {
            "Minimal spanning tree algorithms",
            "Shortest path in graph algorithms",
            "Exit program"
    };

    while (chooseSubMenu != 3) {
        displayMenuOptions(mainMenuOptions);
        getUserChoice(chooseSubMenu);

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
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Error: Please re-enter your choice" << std::endl;
                break;
        }
    }
}

void Menu::displayMenuOptions(const std::vector<std::string> &options) {
    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << i + 1 << ". " << options[i] << std::endl;
    }
    std::cout << std::endl;
}

void Menu::getUserChoice(int &choice) {
    std::cout << ">> ";
    std::cin >> choice;
    std::cout << std::endl;
}

void Menu::showFirstLayer() {
    const std::vector<std::string> firstLayerMenuOptions = {
            "Load data from file",
            "Generate a random graph",
            "Display the graph",
            "Prim's algorithm",
            "Kruskal's algorithm",
            "Exit to main menu"
    };

    while (subMenuNumber != 6) {
        displayMenuOptions(firstLayerMenuOptions);
        getUserChoice(subMenuNumber);

        switch (subMenuNumber) {
            case 1:
                loadGraphFromFile();
                break;
            case 2:
                generateRandomGraph();
                break;
            case 3:
                displayGraph();
                break;
            case 4:
                runPrimAlgorithm();
                break;
            case 5:
                runKruskalAlgorithm();
                break;
            case 6:
                std::cout << "Returning to main menu." << std::endl;
                break;
            default:
                std::cout << "Error: Please re-enter your choice" << std::endl;
                break;
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
            "Exit to main menu"
    };

    while (subMenuNumber != 6) {
        displayMenuOptions(secondLayerMenuOptions);
        getUserChoice(subMenuNumber);

        switch (subMenuNumber) {
            case 1:
                loadGraphFromFile();
                break;
            case 2:
                generateRandomGraph();
                break;
            case 3:
                displayGraph();
                break;
            case 4:
                runDijkstraAlgorithm();
                break;
            case 5:
                runBellmanFordAlgorithm();
                break;
            case 6:
                std::cout << "Returning to main menu." << std::endl;
                break;
            default:
                std::cout << "Error: Please re-enter your choice" << std::endl;
                break;
        }
    }
}

void Menu::loadGraphFromFile() {
    std::cout << "Enter file name: ";
    std::cin >> filename;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    file >> temp[0] >> temp[1];
    graph.initializeGraph(temp[1]);

    for (int i = 0; i < temp[0]; ++i) {
        file >> temp[2] >> temp[3] >> temp[4];
        graph.addEdge(temp[2], temp[3], temp[4]);
    }

    file.close();
}

void Menu::generateRandomGraph() {
    std::cout << "Enter number of vertices: ";
    std::cin >> temp[0];
    std::cout << "Enter density of graph in %: ";
    std::cin >> temp[1];
    std::cout << std::endl;
    graph.generateRandomGraph(temp[0], static_cast<float>(temp[1]));
}

void Menu::displayGraph() {
    std::cout << std::endl;
    graph.printList();
    graph.printMatrix();
    std::cout << std::endl;
}

void Menu::runPrimAlgorithm() {
    auto primPtr = std::make_unique<Prim>();
    auto primDecoratorPtr = std::make_unique<PrimDecorator>(std::move(primPtr));

    std::cout << std::endl;
    primDecoratorPtr->primAlgorithm(graph, true);
    std::cout << std::endl;
    primDecoratorPtr->primAlgorithmMatrix(graph, true);
    std::cout << std::endl;
}

void Menu::runKruskalAlgorithm() {
    auto kruskalPtr = std::make_unique<Kruskal>();
    auto kruskalDecoratorPtr = std::make_unique<KruskalDecorator>(std::move(kruskalPtr));

    std::cout << std::endl;
    kruskalDecoratorPtr->kruskalAlgorithm(graph, true);
    std::cout << std::endl;
    kruskalDecoratorPtr->kruskalAlgorithmMatrix(graph, true);
    std::cout << std::endl;
}

void Menu::runDijkstraAlgorithm() {
    auto dijkstraPtr = std::make_unique<Djistra>();
    auto dijkstraDecoratorPtr = std::make_unique<DjistraDecorator>(std::move(dijkstraPtr));

    std::cout << "Enter start vertex: ";
    std::cin >> temp[0];
    std::cout << "Enter end vertex: ";
    std::cin >> temp[1];
    std::cout << std::endl;

    dijkstraDecoratorPtr->findShortestPathList(graph, temp[0], temp[1], true);
    std::cout << std::endl;
    dijkstraDecoratorPtr->findShortestPathMatrix(graph, temp[0], temp[1], true);
    std::cout << std::endl;
}

void Menu::runBellmanFordAlgorithm() {
    auto fordBellmanPtr = std::make_unique<FordBellman>();
    auto fordBellmanDecoratorPtr = std::make_unique<FordBellmanDecorator>(std::move(fordBellmanPtr));

    std::cout << "Enter start vertex: ";
    std::cin >> temp[0];
    std::cout << "Enter end vertex: ";
    std::cin >> temp[1];
    std::cout << std::endl;

    fordBellmanDecoratorPtr->findShortestPathList(graph, temp[0], temp[1], true);
    std::cout << std::endl;
    fordBellmanDecoratorPtr->findShortestPathMatrix(graph, temp[0], temp[1], true);
    std::cout << std::endl;
}
