#include <string>

class Solution {
public:
    int minChanges(std::string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] != s[i + 1]) {
                cnt++;
            }
        }
        return cnt;
    }
};