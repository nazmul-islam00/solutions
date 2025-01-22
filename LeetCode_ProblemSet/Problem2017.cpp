#include <vector>


class Solution {
public:
    long long gridGame(std::vector<std::vector<int>>& grid) {
        int n = grid[0].size();
        std::vector<long long> firstRowPrefix = std::vector<long long>(n, grid[0][0]);
        std::vector<long long> secondRowSuffix = std::vector<long long>(n, grid[1][n - 1]);

        for (int i = 1; i < n; i++) {
            firstRowPrefix[i] = firstRowPrefix[i - 1] + grid[0][i];
            secondRowSuffix[n - 1 - i] = secondRowSuffix[n - i] + grid[1][n - 1 - i];
        }

        long long maxSum = firstRowPrefix[n - 1] - firstRowPrefix[0]; 
        for (int i = 1; i < n; i++) {
            long long firstRowScore = firstRowPrefix[n - 1] - firstRowPrefix[i];
            long long secondRowScore = secondRowSuffix[0] - secondRowSuffix[i];
            if (firstRowScore < maxSum && secondRowScore < maxSum) {
                maxSum = std::max(firstRowScore, secondRowScore);
            }
        }

        return maxSum;
    }
};
