#include <vector>


class Solution {
public:
    int minZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        if (isZeroArray(nums, queries, -1)) return 0;

        int l = 0, r = queries.size(), mid;

        while (l < r) {
            mid =  (l + r) / 2;

            if (!isZeroArray(nums, queries, mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return (l < queries.size() && isZeroArray(nums, queries, l)) ? (l + 1) : -1;
    }

private:
    bool isZeroArray(const std::vector<int>& nums, const std::vector<std::vector<int>>& queries, int k) {
        std::vector<int> temp(nums);
        std::vector<int> diff(nums.size() + 1);
        diff[0] = nums[0], diff[nums.size()] = 0;

        for (int i = 1; i < nums.size(); i++) {
            diff[i] = nums[i] - nums[i - 1];
        }

        for (int i = 0; i <= k; i++) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diff[l] -= val;
            diff[r + 1] += val;
        }

        if ((temp[0] = diff[0]) > 0) return false;

        for (int i = 1; i < temp.size(); i++) {
            temp[i] = temp[i - 1] + diff[i];
            if (temp[i] > 0) return false;
        }

        return true;
    }
};