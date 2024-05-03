//
// Created by HP on 5/3/2024.
//

#ifndef PROBLEM165_H
#define PROBLEM165_H
#include <string>
#include <vector>

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        std::vector<int> v1, v2;
        int num = 0;
        for(int i = 0; i < version1.length(); i++) {
            if(version1[i] == '.') {
                v1.push_back(num);
                num = 0;
                continue;
            }
            num *= 10;
            num += version1[i] - '0';
        }
        v1.push_back(num);
        num = 0;
        for(int i = 0; i < version2.length(); i++) {
            if(version2[i] == '.') {
                v2.push_back(num);
                num = 0;
                continue;
            }
            num *= 10;
            num += version2[i] - '0';
        }
        v2.push_back(num);
        int ind = 0;
        while(ind < v1.size() && ind < v2.size()) {
            if(v1[ind] > v2[ind]) {
                return 1;
            } else if(v1[ind] < v2[ind]) {
                return -1;
            }
            ind++;
        }
        while(ind < v1.size()) {
            if(v1[ind++]) {
                return 1;
            }
        }
        while(ind < v2.size()) {
            if(v2[ind++]) {
                return -1;
            }
        }
        return 0;
    }
};



#endif //PROBLEM165_H
