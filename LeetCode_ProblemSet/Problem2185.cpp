#include <vector>
#include <string>


class Solution {
public:
    int prefixCount(std::vector<std::string>& words, std::string pref) {
        int cnt = 0;
        for (const std::string& word : words) {
            cnt += word.find(pref) == 0;
        }
        return cnt;
    }
};