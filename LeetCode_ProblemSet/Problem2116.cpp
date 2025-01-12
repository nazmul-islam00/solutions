#include <string>
#include <stack>


class Solution {
public:
    bool canBeValid(std::string s, std::string locked) {
        // odd length string cannot be balanced
        if (s.size() % 2) return false;

        std::stack<int> unlocked, lockedOpening;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') unlocked.push(i);
            else if (s[i] == '(') lockedOpening.push(i);
            else {
                // prioritize locked opening parenthesis
                if (!lockedOpening.empty()) lockedOpening.pop();
                // no locked opening parethesis, free to remove any unlocked one
                else if (!unlocked.empty()) unlocked.pop();
                else return false;
            }
        }

        while (!lockedOpening.empty()) {
            if (unlocked.empty()) return false;
            // any locked opening must have some following unlocked option
            if (unlocked.top() < lockedOpening.top()) return false;
            lockedOpening.pop();
            unlocked.pop();
        }

        return true;
    }
};