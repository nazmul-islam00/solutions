#include <string>
#include <vector>

class Solution {
   public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> answer;
        int firstOccurrences[26];
        int lastOccurrences[26];

        for (int idx = 0; idx < 26; idx++) {
            firstOccurrences[idx] = lastOccurrences[idx] = -1;
        }

        for (int idx = 0; idx < s.length(); idx++) {
            if (firstOccurrences[s[idx] - 'a'] == -1) firstOccurrences[s[idx] - 'a'] = idx;
            lastOccurrences[s[idx] - 'a'] = idx;
        }

        int idx = 0;
        while (idx < s.length()) {
            char c = s[idx];

            int maxLast = lastOccurrences[c - 'a'], initMax = lastOccurrences[c - 'a'];
            do {
                initMax = maxLast;
                for (int i = 0; i < 26; i++) {
                    if (firstOccurrences[i] < maxLast) {
                        maxLast = std::max(maxLast, lastOccurrences[i]);
                    }
                }
            } while (maxLast != initMax);

            answer.push_back(maxLast - idx + 1);
            idx = maxLast + 1;
        }

        return answer;
    }
};