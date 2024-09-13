#include <vector>

class Solution {
public:
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
        std::vector<int> xorArr(arr.size()), answer(queries.size());
        int curXor = 0;
        for (int i = 0; i < arr.size(); i++) {
            xorArr[i] = curXor = curXor ^ arr[i];
        }
        for (int i = 0; i < queries.size(); i++) {
            int left = queries[i][0], right = queries[i][1];
            answer[i] = (left > 0) ? (xorArr[right] ^ xorArr[left - 1]) : xorArr[right];
        }
        return answer;
    }
};