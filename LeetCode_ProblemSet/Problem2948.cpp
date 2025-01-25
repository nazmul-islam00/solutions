#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>


class Solution {
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
        std::vector<int> sortedNums(nums);
        std::vector<int> answer = std::vector<int>(nums.size());
        std::unordered_map<int, int> groupNos;
        std::unordered_map<int, std::list<int>> groups;
        int groupNo = 0;

        std::sort(sortedNums.begin(), sortedNums.end());
        groupNos[sortedNums[0]] = groupNo;
        groups[groupNo] = std::list<int>(1, sortedNums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (std::abs(sortedNums[i] - sortedNums[i - 1]) > limit) groupNo++;
            groupNos[sortedNums[i]] = groupNo;

            if (groups.find(groupNo) == groups.end()) groups[groupNo] = std::list<int>();
            groups[groupNo].push_back(sortedNums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            answer[i] = *groups[groupNos[nums[i]]].begin();
            groups[groupNos[nums[i]]].pop_front();
        }

        return answer;
    }
};