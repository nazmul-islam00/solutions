#include <vector>
#include <queue>
#include <functional>
#include <algorithm>


class Solution {
private:
    std::vector<int> changeX = {-1, 1, 0, 0};
    std::vector<int> changeY = {0, 0, 1, -1};

public:
    int trapRainWater(std::vector<std::vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        std::priority_queue<
            std::pair<int, std::pair<int, int>>, 
            std::vector<std::pair<int, std::pair<int, int>>>, 
            std::greater<std::pair<int, std::pair<int, int>>>
        > heap;
        std::vector<std::vector<bool>> visited = std::vector<std::vector<bool>>(m, std::vector<bool>(n, false));
        int answer = 0, maxHeight = 0;

        for (int i = 0; i < m; i++) {
            heap.push({heightMap[i][0], {i, 0}});
            heap.push({heightMap[i][n - 1], {i, n - 1}});
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int i = 0; i < n; i++) {
            heap.push({heightMap[0][i], {0, i}});
            heap.push({heightMap[m - 1][i], {m - 1, i}});
            visited[0][i] = visited[m - 1][i] = true;
        }

        while (!heap.empty()) {
            auto p = heap.top();
            heap.pop();
            maxHeight = std::max(maxHeight, p.first);
            answer += maxHeight - p.first;

            for (int i = 0; i < changeX.size(); i++) {
                int newX = p.second.first + changeX[i];
                int newY = p.second.second + changeY[i];

                if (!isInGrid(newX, newY, m, n)) continue;
                if (visited[newX][newY]) continue;

                heap.push({heightMap[newX][newY], {newX, newY}});
                visited[newX][newY] = true;
            }
        }

        return answer;
    }

private:
    bool isInGrid(int i, int j, int m, int n) {
        return 0 <= i && i < m && 0 <= j && j < n;
    }
};