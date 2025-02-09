#include <vector>
#include <unordered_map>


class Solution {
public:
    long long countBadPairs(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i] - i;
            if (freq.find(val) == freq.end()) freq[val] = 1;
            else freq[val]++;
        }

        long long totalPairs = nums.size() * (nums.size() - 1) / 2;
        long long goodPairs = 0;
        for (const auto &[val, freq] : freq) {
            goodPairs += (long long) freq * (freq - 1) / 2;
        }

        return totalPairs - goodPairs; 
    }
};