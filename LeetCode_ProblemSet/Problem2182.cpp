#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>


class Solution {
public:
    std::string repeatLimitedString(std::string s, int repeatLimit) {
        std::vector<int> count(26, 0);
        std::priority_queue<int> pq;
        std::ostringstream result;

        for (char c : s) {
            count[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i]) pq.push(i);
        }

        while (!pq.empty()) {
            int ch1 = pq.top();
            pq.pop();

            while (count[ch1]) {
                result << std::string(std::min(repeatLimit, count[ch1]), char(ch1 + 'a'));
                count[ch1] -= std::min(repeatLimit, count[ch1]);

                if (!count[ch1]) break;
                if (pq.empty()) break; 

                int ch2 = pq.top();
                result << std::string(1, char(ch2 + 'a'));
                count[ch2]--;

                if (!count[ch2]) pq.pop();
            }
        }
         
        return result.str();
    }
};