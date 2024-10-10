#include <vector>
#include <stack>
#include <cmath>

class Solution {
public:
    int maxWidthRamp(std::vector<int>& nums) {
        std::stack<int> st;
        int maxWidth = 0;

        // storce indices only if the value is lesser than the prev one
        // equal ones are not necessary as those would result in lesser width
        for (int i = 0; i < nums.size(); i++) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }   

        // check for the possible ramps
        for (int j = nums.size() - 1; j >= 0; j--) {
            while (!st.empty() && nums[st.top()] <= nums[j]) {
                maxWidth = std::max(maxWidth, j - st.top());
                st.pop();
            }
        }     

        return maxWidth;
    }
};