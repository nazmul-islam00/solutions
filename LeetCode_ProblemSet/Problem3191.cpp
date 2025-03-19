#include <vector>

class Solution {
   public:
    int minOperations(std::vector<int>& nums) {
        int ops = helper(nums, 0);

        if (nums[nums.size() - 1] == 0 ||
            nums[nums.size() - 2] == 0 ||
            nums[nums.size() - 3] == 0)
            return -1;

        return ops;
    }

   private:
    int helper(std::vector<int>& nums, int idx) {
        if (idx == nums.size()) return 0;
        if (nums[idx] == 1) return helper(nums, idx + 1);
        
        nums[idx] = 1;

        if (idx + 1 >= nums.size()) return nums[idx] = 0;
        nums[idx + 1] = (nums[idx + 1] == 0) ? 1 : 0;

        if (idx + 2 >= nums.size()) return nums[idx] = 0;
        nums[idx + 2] = (nums[idx + 2] == 0) ? 1 : 0;

        return 1 + helper(nums, idx + 1);
    }
};