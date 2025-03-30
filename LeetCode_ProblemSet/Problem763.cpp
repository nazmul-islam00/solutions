#include <string>
#include <vector>

class Solution {
   public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> answer;
        int lastOccurrences[26];

        for (int idx = 0; idx < s.length(); idx++) {
            lastOccurrences[s[idx] - 'a'] = idx;
        }

        int start = 0, end = 0;
        for (int idx = 0; idx < s.length(); idx++) {
            end = std::max(end, lastOccurrences[s[idx] - 'a']);

            if (idx == end) {
                answer.push_back(end - start+ 1);
                start = idx + 1;
            }
        }

        return answer;
    }
};