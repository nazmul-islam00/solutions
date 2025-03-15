#include <vector>

class Solution {
   private:
    std::vector<std::vector<int>> dp;

   public:
    int rob(std::vector<int>& nums) {
        dp = std::vector<std::vector<int>>(nums.size() + 2, std::vector<int>(nums.size() + 2, -1));
        return std::max(
            nums[0] + handler(nums, 2, nums.size() - 2),
            handler(nums, 1, nums.size() - 1));
    }

   private:
    int handler(const std::vector<int>& nums, int start, int end) {
        if (start >= nums.size() || start > end) return 0;
        if (start == end) return nums[start];
        if (end - 1 == start) return std::max(nums[start], nums[end]);
        if (dp[start][end] != -1) return dp[start][end];
        return dp[start][end] = std::max(
                   nums[start] + handler(nums, start + 2, end),
                   handler(nums, start + 1, end));
    }
};