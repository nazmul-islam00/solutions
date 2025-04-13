#include <cmath>

class Solution {
   private:
    int mod = 1e9 + 7;

   public:
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n - even;
        return (binaryExp(5, even) * binaryExp(4, odd)) % mod;
    }

   private:
    long long binaryExp(long long a, long long b) {
        if (b == 0) return 1;
        long long res = binaryExp(a, b / 2) % mod;
        long long sq = (res * res) % mod;
        if (b % 2) return (sq * a) % mod;
        return sq % mod;
    }
};