#include <vector>


class Solution {
public:
    std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
    std::vector<int> answer(nums.size(), pivot);
    int idx = 0, ridx = nums.size() - 1;

    for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--) {
        if (nums[i] < pivot) answer[idx++] = nums[i];
        if (nums[j] > pivot) answer[ridx--] = nums[j];
    }

    return answer;
    }   
};