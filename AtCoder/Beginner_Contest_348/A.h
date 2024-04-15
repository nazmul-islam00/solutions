//
// Created by HP on 4/15/2024.
//

#ifndef A_H
#define A_H
#include <iostream>


class Solution {
public:
    void run() {
        int n;
        std::cin >> n;
        for(int i = 1; i <= n; i++)
            if(i % 3) std::cout << 'o';
            else std::cout << 'x';
        std::cout << std::endl;
    }
};



#endif //A_H
