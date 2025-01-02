#include <vector>
#include <string>


class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    std::vector<int> vowelStrings(std::vector<std::string>& words, std::vector<std::vector<int>>& queries) {
        std::vector<int> prefix = std::vector<int>(words.size() + 1, 0);
        std::vector<int> answer = std::vector<int>(queries.size());

        for (int i = 0; i < words.size(); i++) {
            prefix[i + 1] = prefix[i] + ((isVowel(words[i][0]) && isVowel(words[i][words[i].size() - 1])) ? 1 : 0);
        }

        for (int i = 0; i < queries.size(); i++) {
            answer[i] = prefix[queries[i][1] + 1] - prefix[queries[i][0]];
        }

        return answer;
    }
};