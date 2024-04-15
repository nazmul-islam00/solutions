//
// Created by HP on 4/15/2024.
//

#ifndef C_H
#define C_H
#include <iostream>
#include <unordered_map>


class Solution {
public:
    void run() {
        int n;
        std::cin >> n;
        std::unordered_map<int, int> colorWiseMinDeliciousNess;
        for(int i = 0; i < n; i++) {
            int a, c;
            std::cin >> a >> c;
            auto it = colorWiseMinDeliciousNess.find(c);
            if(it == colorWiseMinDeliciousNess.end())
                colorWiseMinDeliciousNess[c] = a;
            else
                it->second = std::min(it->second, a);
        }
        int maxMinDeliciouness = 0;
        for(auto& it : colorWiseMinDeliciousNess)
            maxMinDeliciouness = std::max(maxMinDeliciouness, it.second);
        std::cout << maxMinDeliciouness << std::endl;
    }
};



#endif //C_H
