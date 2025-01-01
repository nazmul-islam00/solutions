#include <string>


class Solution {
public:
    int maxScore(std::string s) {
        int zeros = 0, ones = 0, score = INT_MIN, n = s.length();

        for (int i = 0; i < n - 1; i++) {
            zeros += (s[i] == '0') ? 1 : 0;
            ones += (s[i] == '1') ? 1 : 0;
            score = std::max(score, zeros - ones);
        }

        ones += (s[n - 1] == '1') ? 1 : 0;
        return score + ones;
    }
};