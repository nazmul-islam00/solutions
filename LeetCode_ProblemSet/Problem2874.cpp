#include <vector>

class Solution {
   public:
    long long maximumTripletValue(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> leftMax(n, 0), rightMax(n, 0);
        for (int idx = 1; idx < n; idx++) {
            leftMax[idx] = std::max(leftMax[idx - 1], nums[idx - 1]);
            rightMax[n - 1 - idx] = std::max(rightMax[n - idx], nums[n - idx]);
        }
        
        long long answer = 0;
        for (int idx = 1; idx < n - 1; idx++) {
            answer = std::max(
                answer,
                (long long)(leftMax[idx] - nums[idx]) * rightMax[idx]);
        }
        return answer;
    }
};