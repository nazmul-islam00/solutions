//
// Created by HP on 5/25/2024.
//

#ifndef PROBLEM43_H
#define PROBLEM43_H
#include <algorithm>
#include <string>
#include <vector>


class Solution {
private:
    static void multiplyHelp(std::vector<std::string>& nums, std::string& num1, int num2, int index) {
        std::string ans;
        for(int i = 0; i < index; i++) {
            ans += "0";
        }
        int carry = 0;
        for(int i = num1.size() - 1; i >= 0; i--) {
            int int1 = num1[i] - '0';
            ans += std::to_string((int1 * num2 + carry) % 10);
            carry = (int1 * num2 + carry) / 10;
        }
        if(carry) {
            ans += std::to_string(carry);
        }
        std::reverse(ans.begin(), ans.end());
        nums.push_back(ans);
    }
    static void  add(std::string& num1, std::string& num2) {
        std::string ans = "";
        int carry = 0;
        int ind1 = num1.size() - 1, ind2 = num2.size() - 1;
        while(ind1 >= 0 && ind2 >= 0) {
            ans += std::to_string((carry + num1[ind1] - '0' + num2[ind2] - '0') % 10);
            carry = (carry + num1[ind1--] - '0' + num2[ind2--] - '0') / 10;
        }
        while(ind1 >= 0) {
            ans += std::to_string((carry + num1[ind1] - '0') % 10);
            carry = (carry + num1[ind1--] - '0') / 10;
        }
        while(ind2 >= 0) {
            ans += std::to_string((carry + num2[ind2] - '0') % 10);
            carry = (carry + num2[ind2--] - '0') / 10;
        }
        if(carry) {
            ans += std::to_string(carry);
        }
        std::reverse(ans.begin(), ans.end());
        num1 = ans;
    }
public:
    std::string multiply(std::string num1, std::string num2) {
        std::vector<std::string> nums;
        for(int i = num2.size() - 1; i >= 0; i--) {
            multiplyHelp(nums, num1,int(num2[i] - '0'), num2.size() - 1 - i);
        }
        std::string ans = "0";
        for(auto num : nums) {
            add(ans, num);
        }
        while(ans.size() > 1 && ans[0] == '0') {
            ans = ans.substr(1);
        }
        return ans;
    }
};



#endif //PROBLEM43_H

