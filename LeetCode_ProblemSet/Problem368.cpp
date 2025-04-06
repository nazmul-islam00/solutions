#include <algorithm>
#include <functional>
#include <vector>

class Solution {
   public:
    std::vector<int> largestDivisibleSubset(std::vector<int> &nums) {
        int n = nums.size();

        std::vector<std::pair<int, int>> numsWithIndices(n);
        for (int i = 0; i < n; i++) {
            numsWithIndices[i] = {nums[i], i};
        }

        std::sort(numsWithIndices.begin(), numsWithIndices.end());

        std::vector<int> opt(n, 0);
        std::vector<int> parent(n, -1);
        opt[numsWithIndices[0].second] = 1;
        for (int i = 1; i < n; i++) {
            const auto &[num1, idx1] = numsWithIndices[i];

            for (int j = 0; j < i; j++) {
                const auto &[num2, idx2] = numsWithIndices[j];

                if (num1 % num2 != 0) continue;

                if (1 + opt[idx2] > opt[idx1]) {
                    opt[idx1] = 1 + opt[idx2];
                    parent[idx1] = idx2;
                }
            }

            if (opt[idx1] == 0) opt[idx1] = 1;
        }

        int maxIdx = -1, maxSize = 0;
        for (int i = 0; i < n; i++) {
            if (opt[i] > maxSize) {
                maxSize = opt[i];
                maxIdx = i;
            }
        }

        std::vector<int> answer;
        answer.reserve(n);

        int curIdx = maxIdx;
        while (curIdx != -1) {
            answer.push_back(nums[curIdx]);
            curIdx = parent[curIdx];
        }

        return answer;
    }
};