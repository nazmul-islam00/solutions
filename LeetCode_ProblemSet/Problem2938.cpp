#include <string>

class Solution {
public:
    long long minimumSteps(std::string s) {
        long long ans = 0;
        int cnt = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            cnt += s[i] == '0';
            ans += s[i] == '1' ? cnt : 0;
        }
        return ans;
    }
};