#include <vector>
#include <string>


class Solution {
public:
    int countPrefixSuffixPairs(std::vector<std::string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (words[j].size() <= words[i].size() && words[i].find(words[j]) == 0 && words[i].rfind(words[j]) == words[i].size() - words[j].size()) {
                    count++;
                }
            }
        }
        return count;
    }
};