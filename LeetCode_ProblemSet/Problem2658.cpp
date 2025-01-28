#include <vector>
#include <queue>
#include <functional>
#include <algorithm>


class Solution {
private:
    std::vector<int> changeX = {-1, 1, 0, 0};
    std::vector<int> changeY = {0, 0, -1, 1};

public:
    int findMaxFish(std::vector<std::vector<int>>& grid) {
        int maxFishCount = 0;
        
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 0) continue;
                maxFishCount = std::max(maxFishCount, bfs(grid, row, col));
            }
        }

        return maxFishCount;
    }

private:
    int bfs(std::vector<std::vector<int>>& grid, int row, int col) {
        std::queue<std::pair<int, int>> bfsQueue;
        int m = grid.size(), n = grid[0].size();

        bfsQueue.push({row, col});
        int fishCount = grid[row][col];
        grid[row][col] = 0;

        while (!bfsQueue.empty()) {
            auto curr = bfsQueue.front();
            bfsQueue.pop();

            for (int i = 0; i < changeX.size(); i++) {
                int newRow = curr.first + changeX[i], newCol = curr.second + changeY[i];

                if (!isInGrid(newRow, newCol, m, n)) continue;
                if (grid[newRow][newCol] == 0) continue;
                
                bfsQueue.push({newRow, newCol});
                fishCount += grid[newRow][newCol];
                grid[newRow][newCol] = 0;
            }
        }

        return fishCount;
    }

    bool isInGrid(int i, int j, int m, int n) {
        return 0 <= i && i < m && 0 <= j && j < n;
    }
};
