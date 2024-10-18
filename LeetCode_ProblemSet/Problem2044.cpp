#include <vector>

class Solution {
public:
    int countMaxOrSubsets(std::vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums)
            maxOr |= num;

        std::vector<std::vector<int>> memo(nums.size(), std::vector<int>(maxOr + 1, -1));

        return this->countMaxOrSubsetsHelper(nums, 0, 0, maxOr, memo);
    }

    int countMaxOrSubsetsHelper(const std::vector<int>& nums, int idx, int curOr, int maxOr, std::vector<std::vector<int>>& memo) {
        if (idx == nums.size())
            return curOr == maxOr ? 1 : 0;

        if (memo[idx][curOr] != -1)
            return memo[idx][curOr];

        return memo[idx][curOr] = (
            this->countMaxOrSubsetsHelper(nums, idx + 1, curOr | nums[idx], maxOr, memo) + 
            this -> countMaxOrSubsetsHelper(nums, idx + 1, curOr, maxOr, memo)
        );
    }
};