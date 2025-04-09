#include <unordered_set>
#include <vector>

class Solution {
   public:
    int minOperations(std::vector<int>& nums, int k) {
        std::unordered_set<int> set;
        for (int num : nums) {
            if (num < k) return -1;
            if (num > k) set.insert(num);
        }
        return set.size();
    }
};