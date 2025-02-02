#include <vector>


class Solution {
public:
    bool check(std::vector<int>& nums) {
        if (nums.size() == 1) return true;

        bool foundRotation = false;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1] && foundRotation) return false;
            if (nums[i] > nums[i + 1]) foundRotation = true;
        }

        if (foundRotation) return nums[nums.size() - 1] <= nums[0];
        return true;
    }
};