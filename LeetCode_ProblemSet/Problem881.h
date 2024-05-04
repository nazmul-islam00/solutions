//
// Created by HP on 5/4/2024.
//

#ifndef PROBLEM881_H
#define PROBLEM881_H
#include <algorithm>
#include <vector>


class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        int res = 0;
        std::sort(people.begin(), people.end(), [](auto p1, auto p2) {
            return p1 > p2;
        });
        int upperIndex = 0;
        while(people[upperIndex] == limit) {
            res++;
            upperIndex++;
        }
        int lowerIndex = people.size() - 1;
        while(lowerIndex >= upperIndex) {
            int complement = limit - people[upperIndex];
            if(people[lowerIndex] > complement) {
                res++;
                upperIndex++;
            } else {
                res++;
                upperIndex++;
                lowerIndex--;
            }
        }
        return res;
    }
};



#endif //PROBLEM881_H
