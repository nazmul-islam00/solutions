//
// Created by HP on 5/22/2024.
//

#ifndef PROBLEM131_H
#define PROBLEM131_H
#include <string>
#include <vector>


class Solution {
    bool isPalindrome(std::string s) {
        for(int i = 0; i < s.length() / 2; i++) {
            if(s[i] != s[s.length() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
    void findPalindrome(std::vector<std::vector<std::string>>& ans, std::vector<std::string>& temp, std::string s) {
        // reached the end
        if(s.length() == 0) {
            ans.push_back(temp);
        }
        for(int i = 0; i < s.length(); i++) {
            // generate all substrings starting from the first character
            std::string ss = s.substr(0, i + 1);
            if(isPalindrome(ss)) {
                temp.push_back(ss);
                // call findPalindrome for the rest of the string
                findPalindrome(ans, temp, s.substr(i + 1));
                // pop the last one
                temp.pop_back();
            }
        }
    }
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> temp;
        findPalindrome(ans, temp, s);
        return ans;
    }
};



#endif //PROBLEM131_H
