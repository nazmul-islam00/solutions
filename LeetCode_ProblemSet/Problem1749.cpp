#include <vector>


class Solution {
public:
    int maxAbsoluteSum(std::vector<int>& nums) {
        int maxRes = nums[0], minRes = nums[0];
        int maxEnding = nums[0], minEnding = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maxEnding = std::max(maxEnding + nums[i], nums[i]);
            minEnding = std::min(minEnding + nums[i], nums[i]);

            maxRes = std::max(maxRes, maxEnding);
            minRes = std::min(minRes, minEnding);
        }

        return std::max(maxRes, std::abs(minRes));
    }
};