#include <vector>
#include <queue>
#include <functional>


class Solution {
private:
    std::vector<int> changeX = {-1, 1, 0, 0};
    std::vector<int> changeY = {0, 0, -1, 1};

public:
    std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        std::vector<std::vector<int>> height = std::vector<std::vector<int>>(m, std::vector<int>(n, -1));
        std::queue<std::pair<int, int>> bfsQueue;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (isWater[row][col] == 1) {
                    height[row][col] = 0;
                    bfsQueue.push({row, col});
                }
            }
        }

        while (!bfsQueue.empty()) {
            auto cell = bfsQueue.front();
            bfsQueue.pop();

            for (int i = 0; i < changeX.size(); i++) {
                int newRow = cell.first + changeX[i], newCol = cell.second + changeY[i];
                if (isInGrid(newRow, newCol, m, n) && height[newRow][newCol] == -1) {
                    height[newRow][newCol] = height[cell.first][cell.second] + 1;
                    bfsQueue.push({newRow, newCol});
                }
            }
        }

        return height;
    }

private: 
    bool isInGrid(int row, int col, int m, int n) {
        return 0 <= row && row < m && 0 <= col && col < n;
    }
};