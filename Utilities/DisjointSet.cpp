#include "DisjointSet.h"

DisjointSet::DisjointSet(int n) : parent(n), rank(n, 0){
    std::iota(parent.begin(), parent.end(), 0);
}


int DisjointSet::find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void DisjointSet::Union(int u, int v) {
    int uRoot = find(u);
    int vRoot = find(v);
    if (rank[uRoot] < rank[vRoot])
        parent[uRoot] = vRoot;
    else if (rank[uRoot] > rank[vRoot])
        parent[vRoot] = uRoot;
    else {
        parent[vRoot] = uRoot;
        rank[uRoot]++;
    }
}
