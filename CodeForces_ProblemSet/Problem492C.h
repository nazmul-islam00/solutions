#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void run() {
        int n, r, avg;
        std::cin >> n >> r >> avg;
        std::vector<std::pair<int, int>> ab(n);
        for(int i = 0; i < n; i ++)
            std::cin >> ab[i].first >> ab[i].second;
        std::sort(ab.begin(), ab.end(), [](auto p1, auto p2) {
            return p1.second < p2.second;
        });
        long long sum = 0;
        for(auto p : ab)
            sum += p.first;
        long long needed = (long long) n * avg - sum;
        long long ans = 0;
        int currIndex = 0;
        while(needed > 0) 
            if(needed > r - ab[currIndex].first) {
                ans += (long long) (r - ab[currIndex].first) * ab[currIndex].second;
                needed -= r - ab[currIndex++].first;
            } else {
                ans += needed * ab[currIndex].second;
                needed = 0;
            }
        std::cout << ans << std::endl;
    }
};

