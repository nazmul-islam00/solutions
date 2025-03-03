#include <vector>
#include <string>
#include <unordered_map>


class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, int> indexMap;
        std::vector<std::vector<std::string>> answer;
        answer.reserve(strs.size());
        int idx = 0;

        for (const std::string& str : strs) {
            const std::string encodedString = encode(str);

            if (indexMap.find(encodedString) == indexMap.end()) {
                indexMap[encodedString] = idx++;
                answer.push_back({str});
            } else {
                answer[indexMap[encodedString]].push_back(str);
            }
        }

        return answer;
    }

private:
    std::string encode(const std::string& str) {
        std::string encodedString(" ", str.size());

        std::vector<int> freq(26, 0);
        for (const char ch : str) freq[ch - 'a']++;

        int idx = 0;
        for (int i = 0; i < 26; i++) {
            while (freq[i]--) {
                encodedString[idx++] = char('a' + i);
            }
        }

        return encodedString;
    }
};