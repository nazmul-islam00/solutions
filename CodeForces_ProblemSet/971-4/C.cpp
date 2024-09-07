#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        double x, y, k;
        std::cin >> x >> y >> k;
        int stepsX = std::ceil(x / k);
        int stepsY = std::ceil(y / k);
        
        if (stepsY >= stepsX) {
            std::cout << stepsY * 2 << std::endl; 
            continue;
        } 
        std::cout << stepsX * 2 - 1 << std::endl;
    }
    return 0;
}