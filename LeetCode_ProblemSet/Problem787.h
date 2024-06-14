//
// Created by HP on 5/6/2024.
//

#ifndef PROBLEM787_H
#define PROBLEM787_H
#include <queue>
#include <tuple>
#include <vector>


class Solution {
public:
    std::vector<std::vector<std::pair<int, int>>> getAdj(std::vector<std::vector<int>> flights, int  n) {
        std::vector<std::vector<std::pair<int, int>>> adj(n, std::vector<std::pair<int, int>> ());
        for(auto v : flights) {
            adj[v[0]].push_back({v[1], v[2]});
        }
        return adj;
    }
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
        auto adj = getAdj(flights, n);
        std::vector<int> dist(n, -1);
        dist[src] = 0;
        std::queue<std::tuple<int, int, int>> q;
        q.push(std::make_tuple(0, src, 0));
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int stops = std::get<0>(p), node = std::get<1>(p), dis = std::get<2>(p);
            if(stops > k || node == dst) {
                continue;
            }
            for(auto i : adj[node]) {
                int dstNode = i.first, price = i.second;
                if(dist[dstNode] == -1 || dist[dstNode] > dist[node] + price) {
                    dist[dstNode] = dist[node] + price;
                    q.push(std::make_tuple(stops + 1, dstNode, dist[dstNode]));
                }
            }
        }
        return dist[dst];
    }
};



#endif //PROBLEM787_H
