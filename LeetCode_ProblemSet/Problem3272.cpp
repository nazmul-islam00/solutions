#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
   public:
    long long countGoodIntegers(int n, int k) {
        std::unordered_set<std::string> options;
        int start = std::pow(10, (n - 1) / 2);
        bool odd = n % 2;

        for (int i = start; i < 10 * start; i++) {
            std::string s = std::to_string(i);
            s += std::string(s.rbegin() + odd, s.rend());
            long long num = std::stoll(s);

            if (num % k == 0) {
                std::sort(s.begin(), s.end());
                options.emplace(s);
            }
        }

        std::vector<long long> factorial(n + 1, 1);
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }

        for (const std::string& s : options) {
            std::vector<int> cnt(10, 0);
            for (const char c : s) {
                cnt[c - '0']++;
            }

            long long total = (n - cnt[0]) * factorial[n - 1];
            for (int i : cnt) {
                total /= factorial[i];
            }
            ans += total;
        }

        return ans;
    }
};