//
// Created by HP on 5/2/2024.
//

#ifndef PROBLEM685_H
#define PROBLEM685_H
#include <queue>
#include <vector>


class Solution {
    // get the adjacency list
    void getAdj(std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& adj) {
        for(auto v : edges) {
            adj[v[0]].push_back(v[1]);
        }
    }
    // check is all nodes were visited
    bool checkVisited(std::vector<bool>& visited) {
        for(int i = 1; i < visited.size(); i++) {
            if(!visited[i]) {
                return false;
            }
        }
        return true;
    }
    // reset the visited array
    void resetVisited(std::vector<bool>& visited) {
        for(int i = 1; i < visited.size(); i++) {
            visited[i] = false;
        }
    }
    // bfs
    // void bfs(std::vector<std::vector<int>>& adj, std::vector<int>& excludedEdge, std::vector<bool>& visited, int source = 1) {
    //     visited[source] = true;
    //     std::queue<int> bfsQueue;
    //     bfsQueue.push(source);
    //     while(!bfsQueue.empty()) {
    //         int currNode = bfsQueue.front();
    //         bfsQueue.pop();
    //         for(int i : adj[currNode]) {
    //             if(currNode == excludedEdge[0] && i == excludedEdge[1]) {
    //                 continue;
    //             }
    //             if(!visited[i]) {
    //                 visited[i] = true;
    //                 bfsQueue.push(i);
    //             }
    //         }
    //     }
    // }
    void dfsHelp(std::vector<std::vector<int>>& adj, std::vector<int>& excludedEdge, std::vector<bool>& visited, int source) {
        visited[source] = true;
        for(int i : adj[source]) {
            if(source == excludedEdge[0] && i == excludedEdge[1]) {
                continue;
            }
            if(!visited[i]) {
                dfsHelp(adj, excludedEdge, visited, i);
            }
        }
    }
    void dfs(std::vector<std::vector<int>>& adj, std::vector<int>& excludedEdge, std::vector<bool>& visited) {
        for(int i = 1; i < adj.size(); i++) {
            if(!visited[i]) {
                dfsHelp(adj, excludedEdge, visited, i);
            }
        }
    }
public:
    std::vector<int> findRedundantDirectedConnection(std::vector<std::vector<int>>& edges) {
        // get the adjacency list
        std::vector<std::vector<int>> adj(edges.size() + 1, std::vector<int> ());
        getAdj(edges, adj);
        // visited array
        std::vector<bool> visited(edges.size() + 1, false);
        std::vector<int> answer;
        for(int i = 0; i < edges.size(); i++) {
            dfs(adj, edges[i], visited);
            if(checkVisited(visited)) {
                answer = edges[i];
            }
            resetVisited(visited);
        }
        return answer;
    }
};



#endif //PROBLEM685_H
