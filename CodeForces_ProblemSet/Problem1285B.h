#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class Solution {
public:
    void run() {
        int t;
        std::cin >> t;
        while(t--) {
            int n;
            std::cin >> n;
            std::vector<std::pair<long long, int>> a(n, {0, 1});
            long long sum = 0;
            bool negativeFound = false;
            bool nonZeroFound = false;
            for(int i = 0; i < n; i++) {
                std::cin >> a[i].first;
                sum += a[i].first;
                if(a[i].first != 0) {
                    nonZeroFound = true;
                }
                if(a[i].first < 0) {
                    negativeFound = true;
                }
            }
            //* if all values are zero
            //* sum will be same irrespective of l, r
            if(!nonZeroFound) {
                std::cout << "NO" << std::endl;
                continue;
            }
            //* the max sum is only possible by taking all types
            //* hence adel can't have more than yasser
            if(!negativeFound) {
                std::cout << "YES" << std::endl;
                continue;
            }
            //* get max substring sum
            for(int i = 1; i < n; i++) {
                if(a[i].first < a[i].first + a[i - 1].first) {
                    a[i].first = a[i].first + a[i - 1].first;
                    a[i].second = a[i - 1].second + 1;
                }
            }
            long long maxSum = 0;
            for(int i = 0; i < n; i++) {
                if(a[i].second < n) {
                    maxSum = std::max(maxSum, a[i].first);
                
                }
            }
            if(maxSum >= sum) {
                std::cout << "NO" << std::endl;
            } else {
                std::cout << "YES" << std::endl;
            }
        }
    }
};