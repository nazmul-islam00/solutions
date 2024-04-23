#include <vector>

class Solution {
    // generates adjacency list for the tree
    std::vector<std::vector<int>> getAdj(std::vector<std::vector<int>>& edges, int n) {
        std::vector<std::vector<int>> adj (n, std::vector<int> ());
        for(std::vector<int> v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        return adj;
    }
public:
    /*
    the approach is to start from the leaves and remove them as we go up levels
    this helps to find the min height trees
    */
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        if (n <= 1) 
            return std::vector<int>{0};
        std::vector<std::vector<int>> adj = getAdj(edges, n);
        std::vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) leaves.push_back(i);
        }
        std::vector<int> answer;
        while (!leaves.empty()) {
            answer = leaves;
            std::vector<int> newLeaves;
            for (int leave : leaves) {
                int neighbor = adj[leave][0]; 
                adj[neighbor].erase(remove(adj[neighbor].begin(), adj[neighbor].end(), leave), adj[neighbor].end());
                if (adj[neighbor].size() == 1) 
                    newLeaves.push_back(neighbor);
            }
            leaves = newLeaves;
        }
        return answer;
    }
};