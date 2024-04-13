//
// Created by HP on 4/12/2024.
//

#ifndef PROBLEM383_H
#define PROBLEM383_H
#include <string>
#include <unordered_map>


class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> map;
        for(int i = 0; i < magazine.length(); i++) {
            auto it = map.find(magazine[i]);
            if(it == map.end())
                map.insert({magazine[i], 1});
            else
                it->second = it->second + 1;
        }
        for(int i = 0; i < ransomNote.length(); i ++) {
            auto it = map.find(ransomNote[i]);
            if(it == map.end())
                return false;
            if(it->second == 0)
                return false;
            it->second = it->second - 1;
        }
        return true;
    }
};



#endif //PROBLEM383_H
