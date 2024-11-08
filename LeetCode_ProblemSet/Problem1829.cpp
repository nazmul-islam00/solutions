#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> getMaximumXor(std::vector<int>& nums, int maximumBit) {
        std::vector<int> answer(nums.size());
        int mask = int(std::pow(2, maximumBit)) - 1;
        int xorSum = 0;

        for (int num : nums) {
            xorSum ^= num;
        }

        for (int i = 0; i < nums.size(); i++) {
            answer[i] = mask ^ xorSum;
            xorSum ^= nums[nums.size() - 1 - i];
        }

        return answer;
    }
};