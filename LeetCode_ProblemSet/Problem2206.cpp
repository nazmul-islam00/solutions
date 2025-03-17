#include <unordered_map>
#include <vector>

class Solution {
   public:
    bool divideArray(std::vector<int>& nums) {
        std::unordered_map<int, bool> isOdd;

        for (const int num : nums) {
            if (isOdd.find(num) == isOdd.end())
                isOdd[num] = true;
            else
                isOdd[num] = !isOdd[num];
        }

        for (auto const& p : isOdd) {
            if (p.second) return false;
        }

        return true;
    }
};