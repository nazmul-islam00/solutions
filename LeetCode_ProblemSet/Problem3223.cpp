#include <string>


class Solution {
public:
    int minimumLength(std::string s) {
        int len = s.size();
        int freq[26];
        
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] >= 3) {
                len -= (freq[i] % 2) ? (freq[i] - 1) : (freq[i] - 2);
            }
        }

        return len;
    }
};