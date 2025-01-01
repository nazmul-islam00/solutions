#include <string>


class Solution {
public:
    int maxScore(std::string s) {
        int n = s.length(), zeros = 0, ones;

        for (char c : s) {
            zeros += (c == '0') ? 1 : 0;
        }
        ones = n - zeros;

        int cnt = (s[0] == '0') ? 1 : 0;
        int score = cnt ? (1 + ones) : (ones - 1);
        for (int i = 1; i < n - 1; i ++) {
            cnt += (s[i] == '0') ? 1 : 0;
            score = std::max(score, cnt + ones - ((i + 1) - cnt));
        }
        return score;
    }
};