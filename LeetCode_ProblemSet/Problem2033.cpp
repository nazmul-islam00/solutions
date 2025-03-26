#include <vector>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<std::vector<int>>& grid, int x) {
        std::vector<int> nums;
        nums.reserve(grid.size() * grid[0].size());
        for (const auto& row : grid) {
            for (const auto num : row) {
                nums.push_back(num);
            }
        }
        std::sort(nums.begin(), nums.end());

        int cost = 0, median = nums[nums.size() / 2];
        for (const auto num : nums) {
            if ((median - num) % x != 0) return -1;
            cost += std::abs(median - num) / x; 
        }
        return cost;
    }
};