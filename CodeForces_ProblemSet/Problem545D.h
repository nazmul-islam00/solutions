//
// Created by HP on 4/11/2024.
//

#include <iostream>
#include <vector>
#include <algorithm>

#ifndef PROBLEM545D_H
#define PROBLEM545D_H

class Solution {
public:
    static void run() {
        int _number_of_people;
        std::cin >> _number_of_people;
        std::vector<int> _wait_times(_number_of_people, 0);
        for(int _ind = 0; _ind < _number_of_people; _ind++) {
            std::cin >> _wait_times[_ind];
        }
        sort(_wait_times.begin(), _wait_times.end());
        int _disappointed_people = 0;
        int _current_wait_time = 0;
        for(int _ind = 0; _ind < _number_of_people; _ind++) {
            if(_wait_times[_ind] < _current_wait_time) {
                _disappointed_people++;
                continue;
            }
            _current_wait_time += _wait_times[_ind];
        }
        std::cout << _number_of_people - _disappointed_people << std::endl;
    }
};

#endif //PROBLEM545D_H
