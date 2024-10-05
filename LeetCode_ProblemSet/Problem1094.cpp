#include <vector>

class Solution {
public:
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
        int start[1001] = {0};
        int end[1001] = {0};
        for (const std::vector<int>& trip : trips) {
            start[trip[1]] += trip[0];
            end[trip[2]] += trip[0];
        }
        int cur = 0;
        for (int i = 0; i < 1001; i++) {
            cur += start[i] - end[i];
            if (cur > capacity) {
                return false;
            }
        }
        return true;
    }
};