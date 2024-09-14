#include <vector>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int ans = 0, maxNum = 0, streak = 0;
        for (int num : nums) {
            if (maxNum < num) {
                ans = streak = 0;
                maxNum = num;
            }
            if (maxNum == num) {
                streak++;
            } else {
                streak = 0;
            }
            ans = std::max(ans, streak);
        }
        return ans;
    }
};