//
// Created by HP on 4/12/2024.
//

#ifndef PROBLEM744_H
#define PROBLEM744_H
#include <vector>


class Solution {
public:
    static char nextGreatestLetter(std::vector<char>& letters, char target) {
        for(char c : letters)
            if(c > target)
                return c;
        return letters[0];
    }
};



#endif //PROBLEM744_H
