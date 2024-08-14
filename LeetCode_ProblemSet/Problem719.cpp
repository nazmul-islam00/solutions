#include <vector>

class Solution {
public:
    int smallestDistancePair(std::vector<int>& nums, int k) {
        int max = this->findMax(nums);
        std::vector<int> buckets(max + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                buckets[std::abs(nums[i] - nums[j])]++;
            }
        }

        for (int i = 0; i < buckets.size(); i++) {
            k -= buckets[i];
            if (k <= 0) {
                return i;
            }
        }
        return -1;
    }

    int findMax(std::vector<int>& nums) {
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            max = std::max(max, nums[i]);
        }
        return max;
    }
};