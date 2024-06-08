#ifndef AIZO_2_WITH_STL_TIMERDECORATOR_H
#define AIZO_2_WITH_STL_TIMERDECORATOR_H

#include <memory>
#include "../Algorithms/MST/Prim.h"
#include "../Algorithms/MST/Kruskal.h"
#include "../Algorithms/SP/Djistra.h"
#include "../Algorithms/SP/FordBellman.h"

class PrimDecorator : public Prim {
protected:
    std::unique_ptr<Prim> prim;

public:
    explicit PrimDecorator(std::unique_ptr<Prim> p) : prim(std::move(p)) {}

    void primAlgorithm(Graph& graph, bool writing) override;
    void primAlgorithmMatrix(Graph& graph, bool writing) override;
};

class KruskalDecorator : public Kruskal {
protected:
    std::unique_ptr<Kruskal> kruskal;

public:
    explicit KruskalDecorator(std::unique_ptr<Kruskal> k) : kruskal(std::move(k)) {}

    void kruskalAlgorithm(Graph& graph, bool writing) override;
    void kruskalAlgorithmMatrix(Graph& graph, bool writing) override;
};

class DjistraDecorator : public Djistra {
protected:
    std::unique_ptr<Djistra> djistra;

public:
    explicit DjistraDecorator(std::unique_ptr<Djistra> d) : djistra(std::move(d)) {}

    void findShortestPathList(Graph &graph, int startVertex, int endVertex, bool writing) override;
    void findShortestPathMatrix(Graph &graph, int startVertex, int endVertex, bool writing) override;

};

class FordBellmanDecorator : public FordBellman {
protected:
    std::unique_ptr<FordBellman> fordBellman;

public:
    explicit FordBellmanDecorator(std::unique_ptr<FordBellman> f) : fordBellman(std::move(f)) {}

    void findShortestPathList(Graph &graph, int startVertex, int endVertex, bool writing) override;
    void findShortestPathMatrix(Graph &graph, int startVertex, int endVertex, bool writing) override;
};

#endif //AIZO_2_WITH_STL_TIMERDECORATOR_H
