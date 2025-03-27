#include <unordered_map>
#include <vector>

class Solution {
   public:
    int minimumIndex(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        int dominantElement = -1, cnt = 0, pre = 0;
        for (const auto num : nums) {
            if (freq.find(num) == freq.end())
                freq[num] = 1;
            else
                freq[num]++;

            if (freq[num] > cnt) {
                cnt = freq[num];
                dominantElement = num;
            }
        }

        for (int idx = 0; idx < nums.size() - 1; idx++) {
            if (nums[idx] == dominantElement) pre++;

            bool dominantLeft = pre > (idx + 1) / 2;
            bool dominantRight = (cnt - pre) > (nums.size() - idx - 1) / 2;
            if (dominantLeft && dominantRight) return idx;
        }

        return -1;
    }
};