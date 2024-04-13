//
// Created by HP on 4/11/2024.
//

#include <iostream>
#include <string>
#include <vector>

/*
  this class finds -
    the max possible even number from a given integer
*/

#ifndef PROBLEM508B_H
#define PROBLEM508B_H

class Solution {
private:
    char _get_char_from_digit(int _num) {
        return (char)(_num + 48);
    }
public:
    void run() {

        // input
        std::string _exchange_rate;
        std::cin >> _exchange_rate;

        std::vector<int> _digit_counts(10, 0);

        for(int _ind = 0; _ind < _exchange_rate.length(); _ind++) {
            // conversion from ASCII
            _digit_counts[_exchange_rate[_ind] - 48]++;
        }

        if(!_digit_counts[0] && !_digit_counts[2] && !_digit_counts[4] && !_digit_counts[6] && !_digit_counts[8]) {
            std::cout << -1 << std::endl;
            return;
        }

        std::string _max_even_exchange_rate = "";

        // add all 9s
        for(int _ind = 0; _ind < _digit_counts[9]; _ind++)
            _max_even_exchange_rate += _get_char_from_digit(9);

        // add all except one 8
        for(int _ind = 0; _ind < _digit_counts[8] - 1; _ind++) {
            _max_even_exchange_rate += _get_char_from_digit(8);
            _digit_counts[8]--;
        }

        // if any other even digit exists add 8
        if((_digit_counts[0] || _digit_counts[2] || _digit_counts[4] || _digit_counts[6]) && _digit_counts[8]) {
            _max_even_exchange_rate += _get_char_from_digit(8);
            _digit_counts[8]--;
        }

        // add all 7s
        for(int _ind = 0; _ind < _digit_counts[7]; _ind++)
            _max_even_exchange_rate += _get_char_from_digit(7);

        // add all except one 6
        for(int _ind = 0; _ind < _digit_counts[6] - 1; _ind++) {
            _max_even_exchange_rate += _get_char_from_digit(6);
            _digit_counts[6]--;
        }

        // if any other even digit exists add 6
        if((_digit_counts[0] || _digit_counts[2] || _digit_counts[4]) && _digit_counts[6]) {
            _max_even_exchange_rate += _get_char_from_digit(6);
            _digit_counts[6]--;
        }

        // add all 5s
        for(int _ind = 0; _ind < _digit_counts[5]; _ind++)
            _max_even_exchange_rate += _get_char_from_digit(5);

        // add all except one 4
        for(int _ind = 0; _ind < _digit_counts[4] - 1; _ind++) {
            _max_even_exchange_rate += _get_char_from_digit(4);
            _digit_counts[4]--;
        }

        // if any other even digit exists add 4
        if((_digit_counts[0] || _digit_counts[2]) && _digit_counts[4]) {
            _max_even_exchange_rate += _get_char_from_digit(4);
            _digit_counts[4]--;
        }

        // add all 3s
        for(int _ind = 0; _ind < _digit_counts[3]; _ind++)
            _max_even_exchange_rate += _get_char_from_digit(3);

        // add all except one 2
        for(int _ind = 0; _ind < _digit_counts[2] - 1; _ind++) {
            _max_even_exchange_rate += _get_char_from_digit(2);
            _digit_counts[2]--;
        }

        // if any other even digit exists add 2
        if(_digit_counts[0] && _digit_counts[2]) {
            _max_even_exchange_rate += _get_char_from_digit(2);
        _digit_counts[2]--;
        }

        // add all 1s
        for(int _ind = 0; _ind < _digit_counts[1]; _ind++)
            _max_even_exchange_rate += _get_char_from_digit(1);

        // add all 0s
        for(int _ind = 0; _ind < _digit_counts[0]; _ind++)
            _max_even_exchange_rate += _get_char_from_digit(0);

        // dump all evens
        if(_digit_counts[8])
            _max_even_exchange_rate += _get_char_from_digit(8);
        if(_digit_counts[6])
            _max_even_exchange_rate += _get_char_from_digit(6);
        if(_digit_counts[4])
            _max_even_exchange_rate += _get_char_from_digit(4);
        if(_digit_counts[2])
            _max_even_exchange_rate += _get_char_from_digit(2);

        // print answer
        std::cout << _max_even_exchange_rate << std::endl;
    }
};

#endif //PROBLEM508B_H
