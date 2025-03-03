#include <vector>

class Solution {
   public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> prefixProduct(nums.size()), postfixProduct(nums.size());
        std::vector<int> answer(nums.size());
        prefixProduct[0] = postfixProduct[nums.size() - 1] = 1;

        for (int i = 0, j = nums.size() - 1; i < nums.size() - 1; i++, j--) {
            prefixProduct[i + 1] = prefixProduct[i] * nums[i];
            postfixProduct[j - 1] = postfixProduct[j] * nums[j];
        }

        for (int i = 0; i < nums.size(); i++) {
            answer[i] = prefixProduct[i] * postfixProduct[i];
        }

        return answer;
    }
};