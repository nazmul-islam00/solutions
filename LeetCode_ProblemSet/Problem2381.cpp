#include <vector>
#include <string>


class Solution {
public:
    std::string shiftingLetters(std::string s, std::vector<std::vector<int>>& shifts) {
        std::vector<int> prefix = std::vector<int>(s.size() + 1, 0);

        for (const std::vector<int>& shift : shifts) {
            prefix[shift[0]] += (shift[2] == 1) ? 1 : -1;
            prefix[shift[1] + 1] += (shift[2] == 1) ? -1 : 1;
        }

        int currShift = 0;
        for (int i = 0; i < s.size(); i++) {
            currShift = (currShift + prefix[i]) % 26;
            currShift += (currShift < 0) ? 26 : 0;
            s[i] = 'a' + (s[i] - 'a' + currShift) % 26;
        }

        return s;
    }
};