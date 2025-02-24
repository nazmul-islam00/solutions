#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    int mostProfitablePath(std::vector<std::vector<int>>& edges, int bob, std::vector<int>& amount) {
        const std::vector<std::vector<int>> adjacencyList = getAdjacencyList(edges);
        const std::unordered_map<int, int> timeStamps = simulateBob(adjacencyList, bob);
        const std::vector<int> aliceEarnings = simulateAlice(timeStamps, adjacencyList, amount);
        return getMaxEarning(adjacencyList, aliceEarnings);
    }

   private:
    int getMaxEarning(const std::vector<std::vector<int>>& adjacencyList, const std::vector<int>& earnings) {
        int maxEarning = INT32_MIN;
        for (int node = 1; node < earnings.size(); node++) {
            if (adjacencyList[node].size() == 1) maxEarning = std::max(maxEarning, earnings[node]);
        }
        return maxEarning;
    }

    const std::vector<int> simulateAlice(const std::unordered_map<int, int>& timeStamps, const std::vector<std::vector<int>>& adjancencyList, const std::vector<int>& amount) {
        std::vector<int> aliceEarnings(adjancencyList.size(), 0);
        std::vector<bool> visited(adjancencyList.size(), false);
        std::queue<std::pair<int, int>> bfsQueue;

        bfsQueue.push(std::make_pair(0, 0));
        visited[0] = true;
        aliceEarnings[0] = amount[0];

        while (!bfsQueue.empty()) {
            int node = bfsQueue.front().first, time = bfsQueue.front().second;
            bfsQueue.pop();

            for (const int neighbor : adjancencyList[node]) {
                if (visited[neighbor]) continue;

                int bobVisitTime = (timeStamps.find(neighbor) == timeStamps.end()) ? adjancencyList.size() : timeStamps.find(neighbor)->second;

                if (bobVisitTime > (time + 1)) aliceEarnings[neighbor] = aliceEarnings[node] + amount[neighbor];
                else if (bobVisitTime == (time + 1)) aliceEarnings[neighbor] = aliceEarnings[node] + amount[neighbor] / 2;
                else aliceEarnings[neighbor] = aliceEarnings[node];

                visited[neighbor] = true;
                bfsQueue.push(std::make_pair(neighbor, time + 1));
            }
        }

        return aliceEarnings;
    }

    const std::unordered_map<int, int> simulateBob(const std::vector<std::vector<int>>& adjacencyList, int bob) {
        std::vector<int> parent(adjacencyList.size(), -1);
        std::unordered_map<int, int> timeStamps;
        std::queue<std::pair<int, int>> bfsQueue;
        int lastTime = -1;

        bfsQueue.push(std::make_pair(bob, 0));
        timeStamps[bob] = 0;
        parent[bob] = bob;

        while (!bfsQueue.empty()) {
            int node = bfsQueue.front().first, time = bfsQueue.front().second;
            bfsQueue.pop();

            for (const int neighbor : adjacencyList[node]) {
                if (parent[node] == neighbor) continue;

                bfsQueue.push(std::make_pair(neighbor, time + 1));
                parent[neighbor] = node;

                if (neighbor == 0) {
                    lastTime = time + 1;
                    break;
                }
            }
        }

        int currNode = 0;
        while (parent[currNode] != currNode) {
            timeStamps[currNode] = lastTime--;
            currNode = parent[currNode];
        }

        return timeStamps;
    }

    const std::vector<std::vector<int>> getAdjacencyList(const std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> adjacencyList(edges.size() + 1, std::vector<int>());

        for (const auto& edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        return adjacencyList;
    }
};