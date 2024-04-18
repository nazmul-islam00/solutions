#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        std::vector<int> uniqueNums;
        uniqueNums.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) 
            if(uniqueNums[uniqueNums.size() - 1] == nums[i])
                continue;
            else 
                uniqueNums.push_back(nums[i]);
        nums = uniqueNums;
        return nums.size();
    }
};