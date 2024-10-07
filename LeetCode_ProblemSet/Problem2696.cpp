#include <string>
#include <stack>

class Solution {
public:
    int minLength(std::string s) {
        std::stack<char> st;
        for (const char c : s) {
            if (st.empty()) {
                st.push(c);
                continue;
            }
            switch (c) {
                case 'B': {
                    if (st.top() == 'A') {
                        st.pop();
                    } else {
                        st.push(c);
                    }
                    break;
                }
                case 'D': {
                    if (st.top() == 'C') {
                        st.pop();
                    } else {
                        st.push(c);
                    }
                    break;
                }
                default: {
                    st.push(c);
                    break;
                }
            }
        }
        return st.size();
    }
};