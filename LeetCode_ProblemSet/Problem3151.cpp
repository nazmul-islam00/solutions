#include <vector>


class Solution {
public:
    bool isArraySpecial(std::vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] % 2 == nums[i] % 2) return false;
        }
        return true;
    }
};