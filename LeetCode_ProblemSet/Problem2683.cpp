#include <vector>


class Solution {
public:
    bool doesValidArrayExist(std::vector<int>& derived) {
        int curr1 = 0, curr2 = 1;
        for (int i = 0; i < derived.size(); i++) {
            curr1 ^= derived[(i + 1) % derived.size()];
            curr2 ^= derived[(i + 1) % derived.size()];
        }
        return curr1 == 0 || curr2 == 1;
    }   
};