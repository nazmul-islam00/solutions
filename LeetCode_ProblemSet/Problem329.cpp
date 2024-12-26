#include <vector>
#include <algorithm>


class Solution {
private:
    std::vector<int> changeX = {-1, 0, 0, 1};
    std::vector<int> changeY = {0, -1, 1, 0};

public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        std::vector<std::vector<int>> paths = std::vector<std::vector<int>>(matrix.size(), std::vector<int>(matrix[0].size(), -1));
        
        for (int i = 0; i < paths.size(); i++) {
            for (int j = 0; j < paths[0].size(); j++) {
                paths[i][j] = increasingPathHelper(paths, matrix, i, j);
            }
        }

        return getLongestIncreasingPath(paths);
    }

private:
    int getLongestIncreasingPath(std::vector<std::vector<int>>& paths) {
        int longestIncreasingPath = paths[0][0];
        for (int i = 0; i < paths.size(); i++) {
            for (int j = 0; j < paths[0].size(); j++) {
                longestIncreasingPath = std::max(longestIncreasingPath, paths[i][j]);
            }
        }
        return longestIncreasingPath;
    }

    int increasingPathHelper(std::vector<std::vector<int>>& paths, std::vector<std::vector<int>>& matrix, int i, int j) {
        if (paths[i][j] != -1) return paths[i][j];

        int currMax = 1;
        for (int idx = 0; idx < 4; idx++) {
            int newX = i + changeX[idx], newY = j + changeY[idx];

            if (isValidCell(matrix.size(), matrix[0].size(), newX, newY) && matrix[i][j] < matrix[newX][newY]) {
                currMax = std::max(currMax, 1 + increasingPathHelper(paths, matrix, newX, newY));
            }
        }
        return paths[i][j] = currMax;
    }

    bool isValidCell(int m, int n, int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
};