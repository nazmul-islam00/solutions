#include <unordered_map>
#include <vector>

struct DisjointSet {
    std::vector<int> parent;

    DisjointSet(int n) {
        parent = std::vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int idx) {
        if (parent[idx] == idx) return idx;
        return parent[idx] = findParent(parent[idx]);
    }

    void unite(int idx1, int idx2) {
        parent[findParent(idx1)] = findParent(idx2);
    }

    bool areConnected(int idx1, int idx2) {
        return findParent(idx1) == findParent(idx2);
    }
};

class Solution {
   public:
    std::vector<int> minimumCost(int n, std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& query) {
        DisjointSet ds(n);
        std::unordered_map<int, int> dist;
        std::vector<int> answer(query.size());

        for (const std::vector<int>& edge : edges) {
            ds.unite(edge[0], edge[1]);
        }

        for (const std::vector<int>& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (!ds.areConnected(u, v)) continue;

            int parent = ds.findParent(u);
            if (dist.find(parent) == dist.end()) dist[parent] = w;
            else dist[parent] &= w;
        }

        for (int i = 0; i < query.size(); i++) {
            int s = query[i][0], t = query[i][1];
            if (!ds.areConnected(s, t)) answer[i] = -1;
            else answer[i] = dist[ds.findParent(s)];
        }

        return answer;
    }
};