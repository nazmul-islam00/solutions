//
// Created by HP on 5/7/2024.
//

#ifndef PROBLEM682_H
#define PROBLEM682_H
#include <stack>
#include <string>
#include <vector>


class Solution {
    int getNum(std::string str) {
        int num = 0;
        bool flag = false;
        int i = 0;
        if(str[0] == '-') {
            flag = true;
            i++;
        }
        for(; i < str.length(); i++) {
            num *= 10;
            num += str[i] - '0';
        }
        return flag? -num : num;
    }
public:
    int calPoints(std::vector<std::string>& operations) {
        std::stack<int> s;
        for(int i = 0; i < operations.size(); i++) {
            if(operations[i] == "+") {
                int num1 = s.top(); s.pop();
                int num2 = s.top();
                s.push(num1);
                s.push(num1 + num2);
            } else if(operations[i] == "D") {
                int num = s.top();
                s.push(num * 2);
            } else if(operations[i] == "C") {
                s.pop();
            } else {
                s.push(getNum(operations[i]));
            }
        }
        int sum = 0;
        while(!s.empty()) {
            sum += s.top(); s.pop();
        }
        return sum;
    }
};



#endif //PROBLEM682_H
