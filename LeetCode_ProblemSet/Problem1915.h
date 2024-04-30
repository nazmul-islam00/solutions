//
// Created by HP on 5/1/2024.
//

#ifndef PROBLEM1915_H
#define PROBLEM1915_H
#include <unordered_map>


class Solution {
public:
    /*
     * the word has only a to j
     * so a 10 bit bit mask is sufficient
     */
    /*
     * the sutraction of bitmasks can be used
     * to represent the parity of chars present between 2 indices
     */
    long long wonderfulSubstrings(std::string word) {
        long long res = 0;
        // bit mask to store the parity of chars
        int mask = 0;
        // mask to store frequencies of bit masks
        std::unordered_map<int, int> freq;
        // freq of 0 representing the empty substr
        freq[0] = 1;
        for(int i = 0; i < word.length(); i++) {
            int bit = word[i] - 'a';
            /*
             * updatet the bit mask up until the previous char
             * this ensures that the parity of char counts is consistent
             */
            /*
             * left shift 1 the number of times represented by bit
             * so 1 is moved to the representing bit of the current char
             * performing the xor flips the previous parity of the current char
             */
            mask ^= (1 << bit);
            /*
             * if this mask was previousl found
             * then for each occurence of the mask,
             * the intermediate substr is a wonderful string with even number of occurences of all
             * if the mask was not encountered before
             * nothing is added to res
             */
            res += (freq.find(mask) == freq.end()) ? 0 : freq.find(mask)->second;
            /*
             * increment the count of occurence of the mask
             */
            freq[mask] = (freq.find(mask) == freq.end()) ? 1 : freq.find(mask)->second + 1;
            /*
             * iterate through a to j
             * for each shift 1 left
             * & flip the correspnding bit
             * but don't assign the changed mask to mask
             * find the mask
             * if it was found then the intermediate substr is a wonderful string
             * else add nothing
             */
            for(int j = 0; j < 10; j++) {
                res += (freq.find(mask ^ (1 << j)) == freq.end()) ? 0 : freq.find(mask ^ (1 << j))->second;
            }
        }
        return res;
    }
};



#endif //PROBLEM1915_H
