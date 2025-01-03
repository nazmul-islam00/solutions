#include <vector>


class Solution {
public:
    int waysToSplitArray(std::vector<int>& nums) {
        std::vector<long> prefix = std::vector<long>(nums.size());
        int splits = 0;

        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            if (2 * prefix[i] >= prefix[nums.size() - 1]) {
                splits++;
            }
        }

        return splits;
    }
};