#include <iostream>
#include <cmath>
#include <algorithm>
class Solution {
public:
    void run() {
        int t;
        std::cin >> t;
        while(t--) {
            int n, g, b;
            std::cin >> n >> g >> b;
            int minG = (n + 1) / 2;
            if(minG <= g) 
                std::cout << n << std::endl;
            else {
                long long fullBCycles = (minG % g) ? minG / g : minG / g - 1;
                long long bDays = std::max(fullBCycles * b, (long long) b);
                long long totalDays = minG + bDays;
                std::cout << std::max(totalDays, (long long) n) << std::endl;
            }
        }
    }
};