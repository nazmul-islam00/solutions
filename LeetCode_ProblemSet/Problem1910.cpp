#include <string>


class Solution {
public:
    std::string removeOccurrences(std::string s, std::string part) {
        while (true) {
            int pos = s.find(part);
            if (pos == std::string::npos) break;
            s.replace(pos, part.size(), "");
        }
        return s;
    }
};