#include <cmath>

class Solution {
   public:
    long long coloredCells(int n) {
        return (long long)2 * std::pow(n, 2) - 2 * n + 1;
    }
};