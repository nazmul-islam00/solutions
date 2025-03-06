#include <vector>

class Solution {
   public:
    std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        long long sum = 0, sqrSum = 0;

        for (const std::vector<int>& row : grid) {
            for (const int num : row) {
                sum += (long long)num;
                sqrSum += (long long)num * num;
            }
        }

        long long sumDiff = sum - (long long)(n * n) * (n * n + 1) / 2;
        long long sqrDiff = sqrSum - (long long)(n * n) * (n * n + 1) * (2 * n * n + 1) / 6;

        return {
            int(sqrDiff / sumDiff + sumDiff) / 2,
            int(sqrDiff / sumDiff - sumDiff) / 2};
    }
};