#include <string>


class Solution {
public:
    std::string clearDigits(std::string s) {
        std::string ans = "";
        for (const char ch : s) {
            if ('0' <= ch && ch <= '9') ans = ans.substr(0, ans.size() - 1);
            else ans += ch;
        }
        return ans;
    }
};