#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "../Graph/Graph.h"
#include "../Algorithms/MST/Kruskal.h"
#include "../Algorithms/MST/Prim.h"
#include "../Algorithms/SP/FordBellman.h"
#include "../Utilities/TimerDecorator.h"
#include "../Algorithms/SP/Djistra.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>


class Menu {
public:
    Menu() : chooseSubMenu(0), subMenuNumber(0) {}

    void show();

private:
    /**
     * Display the menu options
     * @param options list of options
     */
    static void displayMenuOptions(const std::vector<std::string>& options);

    /**
     * Get user choice of menu options
     * @param choice
     */
    static void getUserChoice(int& choice);

    /**
     * Display the first layer of menu
     */
    void showFirstLayer();

    /**
     * Display the second layer of menu
     */
    void showSecondLayer();

    /**
     * Function to load graph from specified file
     */
    void loadGraphFromFile();

    /**
     * Generate random graph
     */
    void generateRandomGraph();

    /**
     * Display graph as list and matrix
     */
    void displayGraph();

    /**
     * Run Prim algorithm for graph
     */
    void runPrimAlgorithm();

    /**
     * Run Kruskal algorithm for graph
     */
    void runKruskalAlgorithm();

    /**
     * Run djistra algorithm for graph
     */
    void runDijkstraAlgorithm();

    /**
     * Run Ford-Ballman algorithm for graph
     */
    void runBellmanFordAlgorithm();

    int chooseSubMenu;
    int subMenuNumber;
    std::string filename;
    Graph graph;
    int temp[5] = {};
};

#endif // MENU_H
