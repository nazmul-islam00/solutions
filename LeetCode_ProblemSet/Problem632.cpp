#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
        int k = nums.size();
        int size = 0;
        for (const std::vector<int>& num : nums) {
            size += num.size();
        }

        std::vector<std::pair<int, int>> merged;
        merged.reserve(size);

        for (int i = 0; i < k; i++) {
            for (int num : nums[i]) {
                merged.emplace_back(num, i);
            }
        }

        std::sort(
            merged.begin(), 
            merged.end(), 
            [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
                return p1.first < p2.first;
            }
        );

        std::vector<int> window(k, 0);
        int start = -1e6, end = 1e6;
        int startIdx = 0;
        int cnt = 0;

        for (int i = 0; i < size; i++) {
            cnt += window[merged[i].second] == 0;
            window[merged[i].second]++;

            // window completed
            while (cnt == k) {
                int range = merged[i].first - merged[startIdx].first;

                if (range < end - start) {
                    start = merged[startIdx].first;
                    end = merged[i].first;
                }

                window[merged[startIdx].second]--;
                cnt -= window[merged[startIdx].second] == 0;
                startIdx++;
            }
        }

        return {start, end};
    }
};