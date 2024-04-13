//
// Created by HP on 4/12/2024.
//

#ifndef PROBLEM374_H
#define PROBLEM374_H



/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * long  guess(long  num);
 */

long guess(long num);

class Solution {
public:
    long  guessNumber(long  n) {

        long lower = 1;
        long  upper = n;
        long  mid = (lower + upper) / 2;

        while(true) {

            long  res = guess(mid);

            if(res == 0)
                break;

            else if(res == 1) {
                lower = mid + 1;
                mid = (upper + lower) / 2;
            }

            else {
                upper = mid - 1;
                mid = (upper + lower) / 2;
            }
        }

        return mid;
    }
};



#endif //PROBLEM374_H
