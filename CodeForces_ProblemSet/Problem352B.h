//
// Created by HP on 4/15/2024.
//

#ifndef PROBLEM352B_H
#define PROBLEM352B_H
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>


class Solution {
public:
    void run() {
        int n;
        std::cin >> n;
        /*
         * structure of the map:
         * key: unique numbers of the input sequence
         * value: {bool to indicate if the progression was already violated, {the unique number again, {latest index of the number for comparison, progression jumping gap}}}
         */
        std::unordered_map<int, std::pair<bool, std::pair<int, std::pair<int, int>>>> uniqueInputs;
        int falsecount = 0;
        for(int i = 0; i < n; i++) {
            int a;
            std::cin >> a;
            auto it = uniqueInputs.find(a);
            if(it == uniqueInputs.end()) {
                uniqueInputs[a] = {true, {a, {i, 0}}};
            } else {
                if(!it->second.first)
                    continue;
                int num = it->second.second.first;
                int prevIndex = it->second.second.second.first;
                int currGap = it->second.second.second.second;
                if(currGap == 0)
                    currGap = i - prevIndex;
                if(i - prevIndex == currGap) {
                    it->second = {true, {num, {i, currGap}}};
                } else {
                    it->second = {false, {num, {i, -1}}};
                    falsecount++;
                }
            }
        }
        std::vector<std::pair<int, std::pair<int, std::pair<int, int>>>> results(uniqueInputs.size());
        std::transform(uniqueInputs.begin(), uniqueInputs.end(), results.begin(), [](auto pair) {
           return pair.second;
        });
        std::cout << uniqueInputs.size() - falsecount << std::endl;
        std::sort(results.begin(), results.end());
        for(auto it : results) {
            if(!it.first)
                continue;
            std::cout << it.second.first << " " << it.second.second.second << std::endl;
        }
    }
};



#endif //PROBLEM352B_H
