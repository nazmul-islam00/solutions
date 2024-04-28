//
// Created by HP on 4/28/2024.
//

#ifndef PROBLEM834_H
#define PROBLEM834_H
#include <vector>


class Solution {
    void dfs1(int node, int parent, std::vector<std::vector<int>>& adj, std::vector<int>& count,std:: vector<int>& ans) {
        for (int child : adj[node]) {
            if (child != parent) {
                dfs1(child, node, adj, count, ans);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
        count[node]++;
    }

    void dfs2(int node, int parent, std::vector<std::vector<int>>& adj, std::vector<int>& count, std::vector<int>& ans, int n) {
        for (int child : adj[node]) {
            if (child != parent) {
                ans[child] = ans[node] - count[child] + n - count[child];
                dfs2(child, node, adj, count, ans, n);
            }
        }
    }

public:
    std::vector<int> sumOfDistancesInTree(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        std::vector<int> count(n, 0), ans(n, 0);
        dfs1(0, -1, adj, count, ans);
        dfs2(0, -1, adj, count, ans, n);

        return ans;
    }
};




#endif //PROBLEM834_H
