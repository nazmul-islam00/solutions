#include <vector>


class Solution {
public:
    int maximumCandies(std::vector<int>& candies, long long k) {
        long long l = 0, r = getMaxCandies(candies), mid;

        while (l < r) {
            mid = (l + r + 1) / 2;

            if (canGetCandies(candies, k, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }

private:
    bool canGetCandies(const std::vector<int>& candies, long long k, long long c) {
        long long count = 0;
        for (const int candy : candies) count += (long long) candy / c;
        return count >= k;
    }

    long long getMaxCandies(const std::vector<int>& candies) {
        long long maxCandy = 0;
        for (const int candy : candies) maxCandy = std::max(maxCandy, (long long) candy);
        return maxCandy;
    }
};