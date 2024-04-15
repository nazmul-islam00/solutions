#include <stack>
#include <string>

class Solution {
    bool isOpening(char c) {
        switch(c) {
            case '(' : return true;
            case '{' : return true;
            case '[' : return true;
            default  : return false;
        }
    }
    bool isMatching(char c1, char c2) {
        if(c1 == '(' && c2 == ')') return true;
        if(c1 == '{' && c2 == '}') return true;
        if(c1 == '[' && c2 == ']') return true;
        return false;
    }
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            if(st.empty() && !isOpening(s[i])) return false;
            else if(isOpening(s[i])) st.push(s[i]);
            else if(isMatching(st.top(), s[i])) st.pop();
            else return false;
        }
        if(!st.empty()) return false;
        return true;
    }
};
