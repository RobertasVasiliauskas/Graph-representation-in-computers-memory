#ifndef AIZO_2_WITH_STL_MENU_H
#define AIZO_2_WITH_STL_MENU_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "../Graph/Graph.h"
#include "../MyAlgorithms/MST/Kruskal.h"
#include "../MyAlgorithms/MST/Prim.h"
#include "../MyAlgorithms/SP/Djistra.h"
#include "../MyAlgorithms/SP/FordBellman.h"

class Menu {
public:
    void show();
    void showFirstLayer();
    void showSecondLayer();
private:

    int firstLayerNumbers[3] = {1, 2, 3};
    int secondLayerNumbers[5] = {1, 2, 3, 4, 5};

    int temp[10] = {0};
    int subMenuNumber = 0;
    int chooseSubMenu = 0;

    std::string filename;
    std::string stringTmp;

    Graph graph;
};


#endif //AIZO_2_WITH_STL_MENU_H
