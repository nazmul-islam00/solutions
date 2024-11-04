#include <string>

class Solution {
public:
    std::string compressedString(std::string word) {
        std::string answer = "";
        char cur = '\n';
        int cnt = 0, idx = 0;
        while (idx < word.length()) {
            if (cur != word[idx]) {
                if (cnt > 0) {
                    answer += std::to_string(cnt);
                    answer += cur;
                }
                cnt = 1;
                cur = word[idx++];
                continue;
            }
            cnt++;
            if (cnt == 9) {
                answer += "9";
                answer += cur;
                cnt = 0;
            }
            idx++;
        }
        if (cnt > 0) {
            answer += std::to_string(cnt);
            answer += cur;
        }
        return answer;
    }
};