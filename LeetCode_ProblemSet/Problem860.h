//
// Created by HP on 4/18/2024.
//

#ifndef PROBLEM860_H
#define PROBLEM860_H
#include <vector>


class Solution {
public:
    bool lemonadeChange(std::vector<int>& bills) {
        int d5 = 0, d10 = 0, d20 = 0;
        for(int bill : bills) {
            switch(bill) {
                case 5: d5++; break;
                case 10: {
                    if(d5) {
                        d5--;
                        d10++;
                    } else
                        return false;
                    break;
                }
                case 20: {
                    if(d5 && d10) {
                        d5--;
                        d10--;
                        d20++;
                    } else if(d5 >= 3) {
                        d5 -= 3;
                        d20++;
                    } else
                        return false;
                }
            }
        }
        return true;
    }
};



#endif //PROBLEM860_H
