#include <vector>

class Solution {
public:
    int largestCombination(std::vector<int>& candidates) {
        std::vector<int> cnt(24, 0);
        for (int i = 0; i < 24; i++) {
            int mask = 1 << i;
            for (int candidate : candidates) {
                if (candidate & mask) {
                    cnt[i]++;
                }
            }
        }
        return *std::max_element(cnt.begin(), cnt.end());
    }
};