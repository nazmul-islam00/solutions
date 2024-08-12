#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> prefixProduct(nums.size(), 1);
        std::vector<int> suffixProduct(nums.size(), 1);
        std::vector<int> answer(nums.size());

        for (int i = 1; i < nums.size(); i++) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
        }

        for (int i = nums.size() - 2; i > -1; i--) {
            suffixProduct[i] = suffixProduct[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < nums.size(); i++) {
            answer[i] = suffixProduct[i] * prefixProduct[i];
        }

        return answer;
    }
};