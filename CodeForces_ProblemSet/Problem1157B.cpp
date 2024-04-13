#include <iostream>
#include <vector>


class Solution {
public:
    void run() {

        int n;
        std::cin >> n;

        std::vector<int> digits(n ,0);

        for(int i = 0; i < n; i++) {
            char c;
            std::cin >> c;
            digits[i] = c-48;
        }

        std::vector<int> mappings(10, 0);

        for(int i = 1; i < 10; i++) {
            std::cin >> mappings[i];
        }

        bool flag = false;

        // check from left
        for(int i = 0; i < n; i++) {
            if(!flag && mappings[digits[i]] > digits[i]) {
                flag = true;
                digits[i] = mappings[digits[i]];
            } else if(flag) {
                if(mappings[digits[i]] >= digits[i]) {
                    digits[i]  = mappings[digits[i]];
                } else {
                    break;
                }
            }
        }

        for(int i : digits) {
            std::cout << i;
        }
        std::cout << std::endl;
    }
};

// int main() {
//     Solution main;
//     main.run();
// }

