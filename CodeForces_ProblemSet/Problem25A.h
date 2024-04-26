#include <iostream>

class Solution {
public:
    void run() {
        int n;
        std::cin >> n;
        int even = 0, odd = 0, evenInd = 0, oddInd = 0;
        for(int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            switch(x % 2) {
                case 0: even++; evenInd = i + 1; break;
                case 1: odd++; oddInd = i + 1; break;
            }
        }
        std::cout << ((even > odd) ? oddInd : evenInd);
        std::cout << std::endl;
    }
};