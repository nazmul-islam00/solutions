#include <cmath>
#include <iostream>
#include <string>

class Solution {
   public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, std::string s) {
        return (
            count(std::to_string(finish), s, limit) -
            count(std::to_string(start - 1), s, limit));
    }

   private:
    long long count(std::string finish, std::string s, int limit) {
        if (finish.length() < s.length()) return 0;
        if (finish.length() == s.length()) return finish >= s;

        std::string suffix = finish.substr(finish.length() - s.length(), s.length());
        long long ans = 0;
        int prefixLength = finish.length() - s.length();

        for (int digit = 0; digit < prefixLength; digit++) {
            if (limit < (finish[digit] - '0')) return ans += (long long)std::pow(limit + 1, prefixLength - digit);

            ans += (long long)(finish[digit] - '0') * (long long)std::pow(limit + 1, prefixLength - 1 - digit);
        }

        ans += suffix >= s;

        return ans;
    }
};