#include <vector>


class Solution {
public:
    int longestMonotonicSubarray(std::vector<int>& nums) {
        int longest = 1, curr = 1;
        bool increasing = true;

        for (int i = 1; i < nums.size(); i++) {
            if (increasing) {
                if (nums[i - 1] < nums[i]) curr++;
                else if (nums[i - 1] == nums[i]) curr = 1;
                else {
                    curr = 2;
                    increasing = false;
                }
            } else {
                if (nums[i - 1] > nums[i]) curr++;
                else if (nums[i - 1] == nums[i]) curr = 1;
                else {
                    curr = 2;
                    increasing = true;
                }
            }

            longest = std::max(longest, curr);
        }

        return longest;
    }
};