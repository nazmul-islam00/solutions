//
// Created by HP on 4/12/2024.
//

#ifndef PROBLEM496_H
#define PROBLEM496_H
#include <vector>


class Solution {
public:
    static std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> answer(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++) {
            int j = 0;
            for(; j < nums2.size(); j++)
                if(nums1[i] == nums2[j])
                    break;
            for(; j <nums2.size(); j++)
                if(nums2[j] > nums1[i]) {
                    answer[i] = nums2[j];
                    break;
                }
        }
        return answer;
    }
};



#endif //PROBLEM496_H
