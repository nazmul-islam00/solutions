#include <unordered_set>
#include <vector>

class Solution {
   public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> set;
        int longest = 0;

        for (const int num : nums) set.insert(num);

        for (int num : nums) {
            if (set.find(num - 1) != set.end()) continue;

            int len = 1;
            while (set.find(++num) != set.end()) len++;

            longest = std::max(longest, len); 
        }

        return longest;
    }
};