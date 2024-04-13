//
// Created by HP on 4/13/2024.
//

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int sum = 0;
    for(int i = 0; i < n - 1; i++) {
        int a;
        std::cin >> a;
        sum += a;
    }
    std::cout << 0 - sum << std::endl;
}