#include <vector>
#include <unordered_map>

class Solution {
public:
    int minSubarray(std::vector<int>& nums, int p) {
        std::unordered_map<int, int> map;
        std::vector<int> prefix(nums.size());
        std::vector<int> optn(nums.size(), INT32_MAX);
        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum = (prefixSum + nums[i]) % p;
            prefix[i] = prefixSum;
        }
        if (prefixSum == 0) {
            return 0;
        }
        map[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            int needed = (prefix[i] - prefixSum + p) % p;
            if (map.find(needed) != map.end()) {
                optn[i] = i - map[needed];
            }
            map[prefix[i]] = i;
        }
        int len = *std::min_element(optn.begin(), optn.end());
        return (len == INT32_MAX || len == nums.size()) ? -1 : len;
    }
};