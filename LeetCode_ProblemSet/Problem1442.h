//
// Created by HP on 5/30/2024.
//

#ifndef PROBLEM1442_H
#define PROBLEM1442_H
#include <vector>


class Solution {
public:
    int countTriplets(std::vector<int>& arr) {
        std::vector<int> xorArray(arr.size() + 1, arr[0]);
        xorArray[0] = 0;
        for(int i = 1; i < xorArray.size(); i++) {
            xorArray[i] = xorArray[i - 1] ^ arr[i - 1];
        }
        int answer = 0;
        for(int i = 0; i < xorArray.size() - 1; i++) {
            for(int j = i + 1; j < xorArray.size(); j++) {
                if(xorArray[i] == xorArray[j]) {
                    answer += j - i - 1;
                }
            }
        }
        return answer;
    }
};



#endif //PROBLEM1442_H
