#include <vector>


class Solution {
private:
    class UnionFind {
    private:
        std::vector<int> parent;

    public:
        UnionFind(int size) {
            parent.resize(size);
            for (int i = 0; i < size; i++) {
                parent[i] = i;
            }
        }

        int findParent(int node) {
            if (parent[node] == node) return node;
            return findParent(parent[node]);
        }

        void merge(int node1, int node2) {
            int parent1 = findParent(node1), parent2 = findParent(node2);
            parent[parent1] = parent2; 
        }
    };

public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        UnionFind unionFind(edges.size());
        int redundantIndex = -1;

        for (int i = 0; i < edges.size(); i++) {
            int node1 = edges[i][0] - 1, node2 = edges[i][1] - 1;
            if (unionFind.findParent(node1) == unionFind.findParent(node2)) redundantIndex = i;
            unionFind.merge(node1, node2);
        }

        return edges[redundantIndex];
    }
};