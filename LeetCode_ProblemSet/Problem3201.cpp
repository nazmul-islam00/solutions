#include <algorithm>
#include <vector>


class Solution {
public:
    int maximumLength(std::vector<int>& nums) {
        if (nums.size() == 2) return 2;

        int len = 1, firstParity = nums[0] % 2;
        int evenCnt = (firstParity == 0), oddCnt = (firstParity == 1);
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] % 2) == ((len - firstParity) % 2)) len++;
            if ((nums[i] % 2) == 0) evenCnt++;
            else oddCnt++;
        }

        if (oddCnt == 0 || evenCnt == 0) return nums.size();
        return std::max(len, std::max(evenCnt, oddCnt));
    }
};