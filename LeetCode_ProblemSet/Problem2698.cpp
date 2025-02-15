#include <cmath>


class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (partitionPossible(i , i * i)) ans += i * i;
        }
        return ans;
    }

private:
    bool partitionPossible(int n, int m) {
        if (n <= 0) return false;
        if (n == m) return true;
        int mul = 10;
        while ((m / mul) > 0) {
            if (partitionPossible(n - (m % mul), m / mul)) return true;
            mul *= 10;
        }
        return false;
    }
};