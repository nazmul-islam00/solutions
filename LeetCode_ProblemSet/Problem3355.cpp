#include <vector>


class Solution {
public:
    bool isZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        std::vector<int> diff(nums.size() + 1);
        diff[0] = nums[0], diff[nums.size()] = 0;

        for (int i = 1; i < nums.size(); i++) {
            diff[i] = nums[i] - nums[i - 1];
        }

        for (const std::vector<int>& query : queries) {
            int l = query[0], r = query[1];
            diff[l] -= 1;
            diff[r + 1] += 1;
        }

        if ((nums[0] = diff[0]) > 0) return false;
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i - 1] + diff[i];
            if (nums[i] > 0) return false;
        }

        return true;
    }
};