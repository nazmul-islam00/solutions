#include <vector>


class Solution {
public:
    std::vector<int> applyOperations(std::vector<int>& nums) {
        std::vector<int> answer(nums.size(), 0);
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int i = 0, j = 0;
        while (i < nums.size()) {
            if (nums[i] > 0) answer[j++] = nums[i];
            i++;
        }
        return answer;
    }
};