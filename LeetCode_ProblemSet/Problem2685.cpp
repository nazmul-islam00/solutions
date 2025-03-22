#include <vector>

class DisjoinSet {
   private:
    std::vector<int> parent;

   public:
    DisjoinSet(int n) {
        parent = std::vector<int>(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int idx) {
        if (parent[idx] == idx) return idx;
        return parent[idx] = findParent(parent[idx]);
    }

    void merge(int idx1, int idx2) {
        parent[findParent(idx1)] = findParent(idx2);
    }
};

class Solution {
   public:
    int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<bool>> isConnected(n, std::vector<bool>(n, false));
        std::vector<std::vector<int>> components(n, std::vector<int>());
        DisjoinSet ds(n);
        int count = 0;


        for (const std::vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            isConnected[u][v] = isConnected[v][u] = true;
            ds.merge(u, v);
        }

        for (int i = 0; i < n; i++) {
            components[ds.findParent(i)].push_back(i);
        }

        for (int i = 0; i < n; i++) {
            if (components[i].empty()) continue;

            bool connected = true;
            for (int n1 : components[i]) {
                if (!connected) break;

                for (int n2 : components[i]) {
                    if (n1 == n2) continue;
                    if (!isConnected[n1][n2]) {
                        connected = false;
                        break;
                    }
                }
            }

            count += connected;
        }

        return count;
    }
};