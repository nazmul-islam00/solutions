#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <functional>


class Solution {
private:
    class UnionFind {
    private:
        std::vector<int> parent;

    public:
        UnionFind(int size) {
            parent.resize(size);
            for (int i = 0; i < size; i++) parent[i] = i;
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
    int magnificentSets(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> adjacencyList = getAdjacencyList(n, edges);
        std::vector<std::vector<int>> connectedComponents = getConnectedComponents(n, edges);

        int groupCount = 0;
        for (const std::vector<int>& connectedComponent : connectedComponents) {
            if (!isBipartiteGraph(n, adjacencyList, connectedComponent[0])) return -1;

            int count = 0;
            for (const int node : connectedComponent) {
                std::vector<bool> visited(n, false);
                count = std::max(count, getGroupCount(adjacencyList, visited, node));
            }
            groupCount += count;
        }

        return groupCount;
    }

private:
    bool isBipartiteGraph(int n, std::vector<std::vector<int>>& adjacencyList, int src) {
        std::vector<short> group(n, -1);
        std::queue<int> nodes;
        nodes.push(src);
        group[src] = 1;

        while (!nodes.empty()) {
            int curr = nodes.front();
            nodes.pop();

            for (const int node : adjacencyList[curr]) {
                if (group[node] == group[curr]) return false;
                if (group[node] != -1) continue;
                group[node] = (group[curr] == 1) ? 2 : 1;
                nodes.push(node);
            }
        } 

        return true;
    }

    std::vector<std::vector<int>> getAdjacencyList(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> adjacencyList = std::vector<std::vector<int>>(n);
        for (const std::vector<int>& edge : edges) {
            int node1 = edge[0] - 1, node2 = edge[1] - 1;
            adjacencyList[node1].push_back(node2);
            adjacencyList[node2].push_back(node1);
        }
        return adjacencyList;
    }

    std::vector<std::vector<int>> getConnectedComponents(int n, std::vector<std::vector<int>>& edges) {
        UnionFind unionFind(n);
        for (const std::vector<int>& edge : edges) {
            int node1 = edge[0] - 1, node2 = edge[1] - 1;
            unionFind.merge(node1, node2);
        }

        int connectedComponentCount = 0;
        std::unordered_map<int, int> parentAssignment;
        std::vector<std::vector<int>> connectedComponents = std::vector<std::vector<int>>(n);

        for (int i = 0; i < n; i++) {
            int parent = unionFind.findParent(i);
            if (parentAssignment.find(parent) == parentAssignment.end()) parentAssignment[parent] = connectedComponentCount++;
            connectedComponents[parentAssignment[parent]].push_back(i);
        }

        connectedComponents.resize(connectedComponentCount);
        return connectedComponents;
    }

    int getGroupCount(std::vector<std::vector<int>>& adjacencyList, std::vector<bool>& visited, int src) {
        std::queue<std::pair<int, int>> bfsQueue;
        bfsQueue.push({src, 1});
        visited[src] = true;
        int maxDepth = 1;

        while (!bfsQueue.empty()) {
            auto curr = bfsQueue.front();
            bfsQueue.pop();

            for (const int i : adjacencyList[curr.first]) {
                if (visited[i]) continue;
                bfsQueue.push({i, curr.second + 1});
                visited[i] = true;
                maxDepth = std::max(maxDepth, curr.second + 1);
            }
        }

        return maxDepth;
    }
};