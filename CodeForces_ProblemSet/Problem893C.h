//
// Created by HP on 4/13/2024.
//

#ifndef PROBLEM893C_H
#define PROBLEM893C_H
#include <algorithm>
#include <iostream>
#include <vector>



class Solution {
private:
    void DFS(std::vector<bool>& visited, std::vector<std::vector<int>>& adj, int i) {
        for(int x : adj[i]) {
            if(!visited[x]) {
                visited[x] = true;
                DFS(visited, adj, x);
            }
        }
    }
public:
    void run() {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::pair<int, int>> c;
        for(int i = 0; i < n; i++) {
            int cost;
            std::cin >> cost;
            c.push_back({cost, i});
        }
        // for(std::pair<int, int> p : c)
        //     std::cout << p.first << " " << p.second << std::endl;
        sort(c.begin(), c.end());
        std::vector<std::vector<int>> adj(n, std::vector<int> ());
        for(int i = 0; i < m; i++) {
            int x, y;
            std::cin >> x >> y;
            adj[x - 1].push_back(y - 1);
            adj[y - 1].push_back(x - 1);
        }
        std::vector<bool> visited(n, false);
        long long sum = 0;
        for(int i = 0; i < c.size(); i++) {
            if(!visited[c[i].second]) {
                // std::cout << c[i].second << " " << c[i].first << std::endl;
                visited[c[i].second] = true;
                sum += c[i].first;
                DFS(visited, adj, c[i].second);
            }
        }
        std::cout << sum << std::endl;
    }
};



#endif //PROBLEM893C_H
