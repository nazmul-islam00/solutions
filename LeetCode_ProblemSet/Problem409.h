//
// Created by HP on 6/4/2024.
//

#ifndef PROBLEM409_H
#define PROBLEM409_H
#include <string>
#include <vector>


class Solution {
public:
    int longestPalindrome(std::string s) {
        std::vector<int> count(52, 0);
        for(auto c : s) {
            if(c <= 'Z') {
                count[c - 'A']++;
            } else {
                count[c - 'a' + 26]++;
            }
        }
        int ans = 0;
        bool flag = false;
        for(int i = 0; i < count.size(); i++) {
            ans += count[i] / 2 * 2;
            flag = flag || count[i] % 2;
        }
        return ans + flag;
    }
};



#endif //PROBLEM409_H
