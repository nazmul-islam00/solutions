#include <unordered_set>
#include <vector>

class Solution {
   public:
    int minimumOperations(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_set<int> set;
        for (int i = n - 1; i >= 0; i--) {
            if (set.find(nums[i]) == set.end())
                set.insert(nums[i]);
            else
                return std::ceil(float(i + 1) / 3);
        }
        return 0;
    }
};