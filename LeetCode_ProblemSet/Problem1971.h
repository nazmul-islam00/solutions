#include <vector>

class Solution {
    std::vector<std::vector<int>> getAdj(std::vector<std::vector<int>> edges, int n) {
        std::vector<std::vector<int>> adj(n, std::vector<int> ());
        for(std::vector<int> v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        return adj;
    }
    void dfs(std::vector<std::vector<int>>& adj, std::vector<bool>& visited, int source) {
        visited[source] = true;
        for(int i : adj[source]) {
            if(!visited[i]) {
                dfs(adj, visited, i);
            }
        }
    }
public:
    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        std::vector<std::vector<int>> adj = getAdj(edges, n);
        std::vector<bool> visited(n, false);
        dfs(adj, visited, source);
        return visited[destination];
    }
};