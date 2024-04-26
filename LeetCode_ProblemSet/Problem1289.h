#include <vector>
#include <algorithm>
#include <functional>

class Solution {
    int helper(std::vector<std::vector<int>>& grid, std::vector<std::pair<int, bool>>& dp, int row, int col) {
        if(row == grid.size() - 1) return grid[row][col];
        if(dp[row * grid.size() + col].second) return dp[row * grid.size() + col].first;
        int answer = INT_MAX;
        for(int i = 0; i < grid.size(); i++) {
            if(i == col) continue;
            answer = std::min(answer, helper(grid, dp, row + 1, i));
        }
        dp[row * grid.size() + col] = {grid[row][col] + answer, true};
        return dp[row * grid.size() + col].first;
    }
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::pair<int, bool>> dp(n * n, {-1, false});
        int answer = INT_MAX;
        for(int i = 0; i < n; i++) {
            answer = std::min(answer, helper(grid, dp, 0, i));
        }
        return answer;
    }
};