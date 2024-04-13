//
// Created by HP on 4/12/2024.
//

#ifndef PROBLEM205_H
#define PROBLEM205_H
#include <string>
#include <unordered_map>


class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> s_map;
        std::unordered_map<char, char> t_map;
        for(int i = 0; i < s.length(); i++) {
            auto it_s = s_map.find(s[i]);
            if(it_s == s_map.end())
                s_map[s[i]] = t[i];
            else
                if(it_s->second != t[i])
                    return false;
            auto it_t = t_map.find(t[i]);
            if(it_t == t_map.end())
                t_map[t[i]] = s[i];
            else
                if(it_t->second != s[i])
                    return false;
        }
        return true;
    }
};



#endif //PROBLEM205_H
