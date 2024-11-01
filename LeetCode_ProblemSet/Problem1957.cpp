#include <string>


class Solution {
public:
    std::string makeFancyString(std::string s) {
        std::string answer = "";
        char cur = '\n';
        int cnt = 0;

        for (char ch : s) {
            if (ch == cur && cnt > 1) {
                continue;
            }
            if (ch == cur) {
                cnt++;
            } else {
                cur = ch;
                cnt = 1;
            }
            answer += ch;
        }

        return answer;
    }
};