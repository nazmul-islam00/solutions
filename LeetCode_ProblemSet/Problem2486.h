//
// Created by HP on 6/3/2024.
//

#ifndef PROBLEM2486_H
#define PROBLEM2486_H
#include <string>


class Solution {
public:
    int appendCharacters(std::string s, std::string t) {
        int sInd = 0, tInd = 0;
        while(tInd < t.size() && sInd < s.size()) {
            if(s[sInd] == t[tInd]) {
                sInd++;
                tInd++;
            } else {
                sInd++;
            }
        }
        return t.size() - tInd;
    }
};



#endif //PROBLEM2486_H
