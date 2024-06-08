# Graph Algorithms Project

## Overview
This project implements several graph algorithms and provides a menu-driven interface for user interaction. The project is designed in C++ and makes use of structured and object-oriented programming techniques. The key features include the implementation of Prim's, Kruskal's, Dijkstra's, and Ford-Bellman algorithms, which can be tested on randomly generated graphs.

## Features
- **User Interaction**: A menu interface allows users to interact with the program and choose different graph operations.
- **Algorithm Testing**: The project supports testing the performance and correctness of graph algorithms on randomly generated graphs.
- **Graph Generation**: Random graph generation with different densities and sizes.
- **Algorithm Implementation**: Includes Prim's, Kruskal's, Dijkstra's, and Ford-Bellman algorithms.

## Project Structure
The project is organized into several directories and files:

- `Graph/Graph.h`: Contains the definition and implementation of the Graph class.
- `Menu/Menu.h`: Contains the implementation of the menu interface.
- `Utilities/TimerDecorator.h`: Contains utilities for timing algorithm execution.
- `Utilities/Utilities.h`: Contains utility functions used throughout the project.

## How to Run
1. **Compile the Project**: Ensure you have a C++ compiler installed. Use the following command to compile the project:
    ```sh
    g++ main.cpp -o graph_algorithms
    ```

2. **Execute the Program**: Run the compiled executable:
    ```sh
    ./graph_algorithms
    ```

3. **Choose Mode**: The program will prompt you to choose between testing mode and interactive mode:
    - **Testing Mode**: Type `yes` when prompted to run the algorithms on randomly generated graphs for performance testing.
    - **Interactive Mode**: Type `no` to enter the menu-driven interface where you can manually select and run different graph algorithms.

## Code Explanation
The `main` function sets up the environment and handles user input to determine the mode of operation. Here's a brief overview of the main components:

- **Testing Mode**: If the user selects testing mode, the program generates random graphs of various sizes and densities. It then runs each algorithm multiple times to gather performance data.
- **Interactive Mode**: If the user selects interactive mode, the program displays a menu allowing the user to choose specific operations.

### Key Classes and Methods
- `Graph`: Manages graph data and operations.
- `Prim`, `Kruskal`, `Dijkstra`, `FordBellman`: Implementations of the respective graph algorithms.
- `Decorator` Classes: Used to add additional functionality, such as timing, to the algorithms.
- `Utilities`: Provides helper functions like random number generation.

### Example Usage
In testing mode, the program generates graphs and runs the algorithms automatically:
```cpp
for (int representativeValue : representativeValues) {
    for (int j : density) {
        for (int k = 0; k < seriesCount; k++) {
            graph.generateRandomGraph(representativeValue, (float) j);
            primDecoratorPtr->primAlgorithm(graph, false);
            primDecoratorPtr->primAlgorithmMatrix(graph, false);
            kruskalDecoratorPtr->kruskalAlgorithm(graph, false);
            kruskalDecoratorPtr->kruskalAlgorithmMatrix(graph, false);
        }
    }
}
```
## Dependencies

- **C++ Standard Library**: The project relies on the C++ Standard Library for core functionalities.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

## Acknowledgements

Special thanks to all contributors and users who have provided valuable feedback to improve this project.
