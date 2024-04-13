//
// Created by HP on 4/12/2024.
//

#ifndef PROBLEM290_H
#define PROBLEM290_H
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>


class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::vector<std::string> words;
        std::stringstream ss(s);
        std::string temp;
        while(ss >> temp)
            words.push_back(temp);
        if(pattern.length() != words.size())
            return false;
        std::unordered_map<char, std::string> char_map;
        std::unordered_map<std::string, char> string_map;
        for(int i = 0; i < pattern.length(); i++) {
            auto char_it = char_map.find(pattern[i]);
            if(char_it == char_map.end())
                char_map[pattern[i]] = words[i];
            else
                if(char_it->second != words[i])
                    return false;
            auto string_it = string_map.find(words[i]);
            if(string_it == string_map.end())
                string_map[words[i]] = pattern[i];
            else
                if(string_it->second != pattern[i])
                    return false;
        }
        return true;
    }
};



#endif //PROBLEM290_H
