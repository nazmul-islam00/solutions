//
// Created by HP on 5/5/2024.
//

#ifndef PROBLEM71_H
#define PROBLEM71_H
#include <stack>
#include <string>
#include <vector>


class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::stack<std::string> s;
        for(int i = 0; i < path.length(); i++) {
            switch (path[i]) {
                case '/': {
                    if(!s.empty() && s.top() == "/") {
                        continue;
                    }
                    s.push("/");
                    break;
                }
                case '.': {
                    std::string temp = ".";
                    while(i + 1 < path.length() && path[i + 1] != '/') {
                        temp += path[i + 1];
                        i++;
                    }
                    if(temp == ".") {

                    } else if (temp == "..") {
                        if(!s.empty()) {
                            s.pop();
                        }
                        if(!s.empty()) {
                            s.pop();
                        }
                    } else {
                        s.push(temp);
                    }
                    break;
                }
                default: {
                    std::string temp = "";
                    temp += path[i];
                    while(i + 1 < path.length() && path[i + 1] != '/') {
                        temp += path[i + 1];
                        i++;
                    }
                    s.push(temp);
                    break;
                }
            }
        }
        if(!s.empty() && s.top() == "/") {
            s.pop();
        }
        std::vector<std::string> finalPath;
        while(!s.empty()) {
            finalPath.push_back(s.top());
            s.pop();
        }
        std::string answer = "";
        for(int i = finalPath.size() - 1; i >= 0; i--) {
            answer += finalPath[i];
        }
        if(answer == "") {
            answer = "/";
        }
        return answer;
    }
};



#endif //PROBLEM71_H
