#include <cmath>
#include <vector>

class Solution {
   public:
    long long repairCars(std::vector<int>& ranks, int cars) {
        long long l = 0, r = cars * cars * *std::max_element(ranks.begin(), ranks.end()), mid;

        while (l < r) {
            mid = l + (r - l) / 2;
            if (possibleToRepairCars(ranks, cars, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return r;
    }

   private:
    bool possibleToRepairCars(const std::vector<int>& ranks, int cars, long long time) {
        for (const int rank : ranks) {
            cars -= std::floor(std::sqrt(time / (long long)rank));
            if (cars <= 0) return true;
        }
        return cars <= 0;
    }
};