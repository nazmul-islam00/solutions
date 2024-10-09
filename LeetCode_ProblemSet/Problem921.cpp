#include <string>
#include <algorithm>
#include <stack>

class Solution {
public:
    int minAddToMakeValid(std::string s) {
        std::stack<char> st;
        int inserts = 0;

        for (char c : s) {
            if (c == '(') {
                st.push(c);
            }
            else if (st.empty()) {
                inserts++;
            } else {
                st.pop();
            }
        }

        return inserts + st.size();
    }
};