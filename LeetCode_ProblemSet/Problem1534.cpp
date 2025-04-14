#include <vector>
#include <cmath>

class Solution {
    public:
    int countGoodTriplets(std::vector<int>& arr, int a, int b, int c) {
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (std::abs(arr[i] - arr[j]) > a) continue;

                for (int k = j + 1; k < arr.size(); k++) {
                    if (std::abs(arr[j] - arr[k]) > b) continue;
                    if (std::abs(arr[i] - arr[k]) > c) continue;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};