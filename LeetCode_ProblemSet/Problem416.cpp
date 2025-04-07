#include <vector>

class Solution {
   public:
    bool canPartition(std::vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        std::vector<bool> dp(target + 1);
        dp[0] = true;
        for (int num : nums) {
            // going forward risks using same element twice
            for (int i = target; i >= num; i--) {
                if (dp[i - num]) {
                    dp[i] = true;
                }
            }
        }
        return dp[target];
    }
};