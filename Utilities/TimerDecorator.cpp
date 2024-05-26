#include <fstream>
#include "TimerDecorator.h"
#include "Timer.h"

void PrimDecorator::primAlgorithm(Graph &graph, bool writing) {

    const char *userProfile = std::getenv("USERPROFILE");

    Timer::checkStartTime();
    Prim::primAlgorithm(graph, writing);
    Timer::checkEndTime();

    if (writing) {
        std::cout << "Algorithm executed in: " << std::chrono::duration_cast<std::chrono::microseconds>(
                Timer::getEndTime() - Timer::getStartTime()).count() << " microseconds" << std::endl << std::endl;
    }

    if (userProfile != nullptr) {
        std::string desktopPath = std::string(userProfile) + "\\Desktop\\collectedData.csv";
        std::ofstream outputFile(desktopPath, std::ofstream::app);
        outputFile << "Prim Algorithm" << "," << "AdjList" << "," << graph.getNumberOfVertices() << ","
                   << graph.getDensityInPercent() << ", "
                   << std::chrono::duration_cast<std::chrono::microseconds>(
                           Timer::getEndTime() - Timer::getStartTime()).count() << std::endl;

        outputFile.close();
    }
}

void PrimDecorator::primAlgorithmMatrix(Graph &graph, bool writing) {

    const char *userProfile = std::getenv("USERPROFILE");

    Timer::checkStartTime();
    Prim::primAlgorithmMatrix(graph, writing);
    Timer::checkEndTime();

    if (writing) {
        std::cout << "Algorithm executed in: " << std::chrono::duration_cast<std::chrono::microseconds>(
                Timer::getEndTime() - Timer::getStartTime()).count() << " microseconds" << std::endl << std::endl;
    }

    if (userProfile != nullptr) {
        std::string desktopPath = std::string(userProfile) + "\\Desktop\\collectedData.csv";
        std::ofstream outputFile(desktopPath, std::ofstream::app);
        outputFile << "Prim Algorithm" << "," << "Matrix" << "," << graph.getNumberOfVertices() << ","
                   << graph.getDensityInPercent() << ", "
                   << std::chrono::duration_cast<std::chrono::microseconds>(
                           Timer::getEndTime() - Timer::getStartTime()).count() << std::endl;

        outputFile.close();
    }
}

void KruskalDecorator::kruskalAlgorithm(Graph &graph, bool writing) {

    const char *userProfile = std::getenv("USERPROFILE");

    Timer::checkStartTime();
    Kruskal::kruskalAlgorithm(graph, writing);
    Timer::checkEndTime();

    if (writing) {
        std::cout << "Algorithm executed in: " << std::chrono::duration_cast<std::chrono::microseconds>(
                Timer::getEndTime() - Timer::getStartTime()).count() << " microseconds" << std::endl << std::endl;
    }

    if (userProfile != nullptr) {
        std::string desktopPath = std::string(userProfile) + "\\Desktop\\collectedData.csv";
        std::ofstream outputFile(desktopPath, std::ofstream::app);
        outputFile << "Kruskal Algorithm" << "," << "AdjList" << "," << graph.getNumberOfVertices() << ","
                   << graph.getDensityInPercent() << ", "
                   << std::chrono::duration_cast<std::chrono::microseconds>(
                           Timer::getEndTime() - Timer::getStartTime()).count() << std::endl;

        outputFile.close();
    }
}

void KruskalDecorator::kruskalAlgorithmMatrix(Graph &graph, bool writing) {

    const char *userProfile = std::getenv("USERPROFILE");

    Timer::checkStartTime();
    Kruskal::kruskalAlgorithmMatrix(graph, writing);
    Timer::checkEndTime();

    if (writing) {
        std::cout << "Algorithm executed in: " << std::chrono::duration_cast<std::chrono::microseconds>(
                Timer::getEndTime() - Timer::getStartTime()).count() << " microseconds" << std::endl << std::endl;
    }

    if (userProfile != nullptr) {
        std::string desktopPath = std::string(userProfile) + "\\Desktop\\collectedData.csv";
        std::ofstream outputFile(desktopPath, std::ofstream::app);
        outputFile << "Kruskal Algorithm" << "," << "Matrix" << "," << graph.getNumberOfVertices() << ","
                   << graph.getDensityInPercent() << ", "
                   << std::chrono::duration_cast<std::chrono::microseconds>(
                           Timer::getEndTime() - Timer::getStartTime()).count() << std::endl;

        outputFile.close();
    }
}

void DjistraDecorator::findShortestPathList(Graph &graph, int startVertex, int endVertex, bool writing) {

    const char *userProfile = std::getenv("USERPROFILE");

    Timer::checkStartTime();
    Djistra::findShortestPathList(graph, startVertex, endVertex, writing);
    Timer::checkEndTime();

    if (writing) {
        std::cout << "Algorithm executed in: " << std::chrono::duration_cast<std::chrono::microseconds>(
                Timer::getEndTime() - Timer::getStartTime()).count() << " microseconds" << std::endl << std::endl;
    }

    if (userProfile != nullptr) {
        std::string desktopPath = std::string(userProfile) + "\\Desktop\\collectedData.csv";
        std::ofstream outputFile(desktopPath, std::ofstream::app);
        outputFile << "Djistra Algorithm" << "," << "AdjList" << "," << graph.getNumberOfVertices() << ","
                   << graph.getDensityInPercent() << ", "
                   << std::chrono::duration_cast<std::chrono::microseconds>(
                           Timer::getEndTime() - Timer::getStartTime()).count() << std::endl;

        outputFile.close();
    }
}

void DjistraDecorator::findShortestPathMatrix(Graph &graph, int startVertex, int endVertex, bool writing) {

    const char *userProfile = std::getenv("USERPROFILE");

    Timer::checkStartTime();
    Djistra::findShortestPathMatrix(graph, startVertex, endVertex, writing);
    Timer::checkEndTime();

    if (writing) {
        std::cout << "Algorithm executed in: " << std::chrono::duration_cast<std::chrono::microseconds>(
                Timer::getEndTime() - Timer::getStartTime()).count() << " microseconds" << std::endl << std::endl;
    }

    if (userProfile != nullptr) {
        std::string desktopPath = std::string(userProfile) + "\\Desktop\\collectedData.csv";
        std::ofstream outputFile(desktopPath, std::ofstream::app);
        outputFile << "Djistra Algorithm" << "," << "Matrix" << "," << graph.getNumberOfVertices() << ","
                   << graph.getDensityInPercent() << ", "
                   << std::chrono::duration_cast<std::chrono::microseconds>(
                           Timer::getEndTime() - Timer::getStartTime()).count() << std::endl;

        outputFile.close();
    }
}

void FordBellmanDecorator::findShortestPathList(Graph &graph, int startVertex, int endVertex, bool writing) {

    const char *userProfile = std::getenv("USERPROFILE");

    Timer::checkStartTime();
    FordBellman::findShortestPathList(graph, startVertex, endVertex, writing);
    Timer::checkEndTime();

    if (writing) {
        std::cout << "Algorithm executed in: " << std::chrono::duration_cast<std::chrono::microseconds>(
                Timer::getEndTime() - Timer::getStartTime()).count() << " microseconds" << std::endl << std::endl;
    }

    if (userProfile != nullptr) {
        std::string desktopPath = std::string(userProfile) + "\\Desktop\\collectedData.csv";
        std::ofstream outputFile(desktopPath, std::ofstream::app);
        outputFile << "FordBellman Algorithm" << "," << "AdjList" << "," << graph.getNumberOfVertices() << ","
                   << graph.getDensityInPercent() << ", "
                   << std::chrono::duration_cast<std::chrono::microseconds>(
                           Timer::getEndTime() - Timer::getStartTime()).count() << std::endl;

        outputFile.close();
    }
}

void FordBellmanDecorator::findShortestPathMatrix(Graph &graph, int startVertex, int endVertex, bool writing) {

    const char *userProfile = std::getenv("USERPROFILE");

    Timer::checkStartTime();
    FordBellman::findShortestPathMatrix(graph, startVertex, endVertex, writing);
    Timer::checkEndTime();

    if (writing) {
        std::cout << "Algorithm executed in: " << std::chrono::duration_cast<std::chrono::microseconds>(
                Timer::getEndTime() - Timer::getStartTime()).count() << " microseconds" << std::endl << std::endl;
    }

    if (userProfile != nullptr) {
        std::string desktopPath = std::string(userProfile) + "\\Desktop\\collectedData.csv";
        std::ofstream outputFile(desktopPath, std::ofstream::app);
        outputFile << "FordBellman Algorithm" << "," << "Matrix" << "," << graph.getNumberOfVertices() << ","
                   << graph.getDensityInPercent() << ", "
                   << std::chrono::duration_cast<std::chrono::microseconds>(
                           Timer::getEndTime() - Timer::getStartTime()).count() << std::endl;

        outputFile.close();
    }
}
