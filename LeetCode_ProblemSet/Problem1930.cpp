#include <string>
#include <vector>
#include <functional>
#include <unordered_set>


class Solution {
public:
    int countPalindromicSubsequence(std::string s) {
        std::vector<std::pair<int, int>> occurences = std::vector<std::pair<int, int>>(26, {-1, -1});
        int palindromeCount = 0;

        for (int i = 0; i < 26; i++) {
            int first = s.find(char('a' + i));
            if (first == std::string::npos) continue;
            int last = s.rfind(char('a' + i));
            occurences[i] = {first, last};
        }

        for (int i = 0; i < 26; i++) {
            std::unordered_set<char> charSet;
            for (int j = occurences[i].first + 1; j < occurences[i].second; j++) {
                charSet.insert(s[j]);
            }
            palindromeCount += charSet.size();
        }

        return palindromeCount;
    }
};