#include <string>
#include <vector>

class Solution {
   public:
    std::string encode(std::vector<std::string>& strs) {
        std::string encodedString = "";
        for (const std::string& str : strs) encodedString += std::to_string(str.length()) + "#" + str;
        return encodedString;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> decodedStrings;
        int idx = 0;

        while (idx < s.length()) {
            int len = 0;
            while (s[idx] != '#') {
                len *= 10;
                len += s[idx++] - '0';
            }
            decodedStrings.push_back(s.substr(++idx, len));
            idx += len;
        }

        return decodedStrings;
    }
};