#include <algorithm>
#include <vector>

class Solution {
   public:
    long long maximumTripletValue(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> leftMax(n);
        std::vector<int> rightMax(n);
        for (int j = 1; j < n; j++) {
            leftMax[j] = std::max(leftMax[j - 1], nums[j - 1]);
            rightMax[n - 1 - j] = std::max(rightMax[n - j], nums[n - j]);
        }
        
        long long answer = 0;
        for (int j = 1; j < n - 1; j++) {
            answer = std::max(
                answer,
                (long long)(leftMax[j] - nums[j]) * rightMax[j]
            );
        }
        return answer;
    }
};