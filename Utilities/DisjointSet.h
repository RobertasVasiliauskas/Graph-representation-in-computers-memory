#ifndef AIZO_2_WITH_STL_DISJOINTSET_H
#define AIZO_2_WITH_STL_DISJOINTSET_H


#include <numeric>
#include <vector>

class DisjointSet {
public:
    explicit DisjointSet(int n);
    int find(int u);
    void Union(int u, int v);

private:
    std::vector<int> parent;
    std::vector<int> rank;
};


#endif //AIZO_2_WITH_STL_DISJOINTSET_H
