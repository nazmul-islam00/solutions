//
// Created by HP on 4/30/2024.
//

#ifndef PROBLEM67_H
#define PROBLEM67_H
#include <algorithm>
#include <string>


class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string res = "";
        int i = a.length() - 1, j = b.length() - 1;
        bool carry = false;
        while(i > -1 && j > -1) {
            int val = a[i] - '0' + b[j] - '0' + carry;
            if(val == 3) {
                val = '1';
                carry = true;
            } else if(val == 2) {
                val = '0';
                carry = true;
            } else {
                carry = false;
                val += '0';
            }
            res += val;
            i--;
            j--;
        }
        while(i > -1) {
            int val = a[i] - '0' + carry;
            if(val == 2) {
                val = '0';
                carry = true;
            } else {
                carry = false;
                val += '0';
            }
            res += val;
            i--;
        }
        while(j > -1) {
            int val = b[j] - '0' + carry;
            if(val == 2) {
                val = '0';
                carry = true;
            } else {
                carry = false;
                val += '0';
            }
            res += val;
            j--;
        }
        if(carry) {
            res += '1';
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};



#endif //PROBLEM67_H
