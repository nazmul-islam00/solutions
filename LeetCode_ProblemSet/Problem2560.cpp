#include <algorithm>
#include <vector>

class Solution {
   public:
    int minCapability(std::vector<int>& nums, int k) {
        int l = *std::min_element(nums.begin(), nums.end());
        int r = *std::max_element(nums.begin(), nums.end());
        int mid;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (isPossible(nums, k, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return r;
    }

   private:
    bool isPossible(const std::vector<int>& nums, int k, int c) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= c) {
                cnt++;
                i++;
                if (cnt == k) return true;
            }
        }
        return cnt == k;
    }
};