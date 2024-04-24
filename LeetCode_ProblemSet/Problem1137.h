#include <vector>

class Solution {
    std::vector<int> nums;
public:
    Solution() {
        nums.resize(38, -1);
        nums[0] = 0;
        nums[1] = nums[2] = 1;
    }
    int tribonacci(int n) {
        if(this->nums[n] != -1) {
            return nums[n];
        }
        return nums[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};