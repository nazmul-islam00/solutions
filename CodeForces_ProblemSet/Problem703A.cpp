#include <iostream>

class Solution {
public:
    static void run() {
        int _number_of_rounds;
        std::cin >> _number_of_rounds;
        int _mishka_wins = 0, _chris_wins = 0;
        while(_number_of_rounds--) {
            int _mishka, _chris;
            std::cin >> _mishka >> _chris;
            if (_mishka > _chris) {
                _mishka_wins++;
            } else if (_mishka < _chris) {
                _chris_wins++;
            }
        }
        if (_mishka_wins > _chris_wins) {
            std::cout << "Mishka" << std::endl;
        } else if (_mishka_wins < _chris_wins) {
            std::cout << "Chris" << std::endl;
        } else {
            std::cout << "Friendship is magic!^^" << std::endl;
        }
    }
};

// int main() {
//     Solution main;
//     main.run();
// }

