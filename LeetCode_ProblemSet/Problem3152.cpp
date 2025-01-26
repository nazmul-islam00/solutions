#include <vector>


class Solution {
public:
    std::vector<bool> isArraySpecial(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        std::vector<int> prefix(nums.size(), 0);
        std::vector<bool> result(queries.size());
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + ((nums[i] % 2) == (nums[i - 1] % 2) ? 0 : 1); 
        }
        for (int i = 0; i < queries.size(); i++) {
            int from = queries[i][0], to = queries[i][1];
            result[i] = (prefix[to] - prefix[from]) == (to - from);
        }
        return result;
    }
};