#include <vector>

class Solution {
public:
    bool kLengthApart(std::vector<int>& nums, int k) {
        int prev = -1;
        for (int idx = 0; idx < nums.size(); idx++) {
            if (nums[idx] == 0) continue;
            if (prev == -1) prev = idx;
            else if (idx - prev - 1 < k) return false;
            else prev = idx; 
        }
        return true;
    }
};