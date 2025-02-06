#include <vector>
#include <unordered_map>


class Solution {
public:
    /*
        since all the integers are distinct, finding pair products would suffice
        to form the permutations from each product, we need to pick two pairs: nP2
        then each pair can be rearranged within itself, 2 arrangements for each
        Thus for each product the result is calculated as 4 * nP2
    */
    int tupleSameProduct(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int product = nums[i] * nums[j];
                if (freq.find(product) == freq.end()) freq[product] = 1;
                else freq[product]++;
            }
        }

        for (auto &[product, freq] : freq) {
            result += 4 * freq * (freq - 1);
        }
        return result;
    }
};