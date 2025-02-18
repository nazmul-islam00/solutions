#include <string>
#include <stack>


class Solution {
public:
    std::string smallestNumber(std::string pattern) {
        std::string answer = "";
        std::stack<int> st;

        /*
            always push in increasing order,
            when pattern is D push onto stack
            this ensures the current pattern is reversed in order 
            and thus decreasing
            when I is seen pop
        */

        for (int idx = 0; idx <= pattern.size(); idx++) {
            st.push(idx + 1);

            if (idx == pattern.size() || pattern[idx] == 'I') {
                while (!st.empty()) {
                    answer += ('0' + st.top());
                    st.pop();
                }
            }
        }

        return answer;
    } 
};