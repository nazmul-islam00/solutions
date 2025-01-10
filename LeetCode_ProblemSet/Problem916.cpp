#include <vector>
#include <string>


class Solution {
public:
    std::vector<std::string> wordSubsets(std::vector<std::string>& words1, std::vector<std::string>& words2) {
        std::vector<std::string> answer;
        answer.reserve(words1.size());
        std::vector<int> cnt1 = std::vector<int>(26, 0);

        for (const std::string& word : words2) {
            std::vector<int> cnt2 = std::vector<int>(26, 0);
            for (const char c : word) {
                cnt2[c - 'a']++;
            }
            
            for (int i = 0; i < 26; i++) {
                cnt1[i] = std::max(cnt1[i], cnt2[i]);
            }
        }

        for (const std::string& word : words1) {
            std::vector<int> cnt2 = std::vector<int>(26, 0);
            for (const char c : word) {
                cnt2[c - 'a']++;
            }

            bool flag = false;
            for (int i = 0; i < 26; i++) {
                if (cnt1[i] > cnt2[i]) {
                    flag = true;
                    break;
                }
            }

            if (!flag) answer.push_back(word);
        }

        return answer;
    } 
};