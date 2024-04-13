//
// Created by HP on 4/12/2024.
//

#ifndef PROBLEM455_H
#define PROBLEM455_H
#include <algorithm>
#include <vector>


class Solution {
public:
    static int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int content = 0;
        int cookie_index = 0;
        int cookie_count = s.size();
        if(cookie_count == 0) {
            return content;
        }
        for(int i = 0; i < g.size(); i++) {
            if(g[i] <= s[cookie_index]) {
                content++;
                cookie_index++;
            } else {
                while(cookie_index < cookie_count && s[cookie_index] < g[i]) {
                    cookie_index++;
                }
                if(cookie_index < cookie_count && s[cookie_index] >= g[i]) {
                    content++;
                    cookie_index++;
                }
            }
            if(cookie_index == cookie_count)
                break;
        }
        return content;
    }
};



#endif //PROBLEM455_H
