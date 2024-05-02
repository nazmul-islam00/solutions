#include <unordered_map>
#include <vector>

class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        int res = -1;
        std::unordered_map<int, int> map;
        for(int i : nums) {
            if(map.find(-i) != map.end()) {
                res = std::max(res, std::abs(i));
            } else {
                map[i] = 1;
            }
        }
        return res;
    }
};
