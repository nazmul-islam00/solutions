#include <vector>

class Solution {
   public:
    int longestNiceSubarray(std::vector<int>& nums) {
        int len = 0, left = 0, used = 0;

        for (int right = 0; right < nums.size(); right++) {
            while ((used & nums[right]) != 0) {
                used ^= nums[left];
                left++;
            }

            used |= nums[right];
            len = std::max(len, right - left + 1);
        }

        return len;
    }
};