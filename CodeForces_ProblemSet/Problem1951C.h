#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void run() {
        int t;
        std::cin >> t;
        while(t--) {
            int n, m, k;
            std::cin >> n >> m >> k;
            std::vector<int> a(n);
            for(int i = 0; i < n; i++)
                std::cin >> a[i];
            std::sort(a.begin(), a.end());
            int currIndex = 0, purchased = 0;
            long long cost = 0;
            while(k) {
                if(k <= m) {
                    cost += (long long)(a[currIndex++] + purchased) * k;
                    k = 0;
                } else {
                    cost += (long long)(a[currIndex++] + purchased) * m;
                    k -= m;
                    purchased += m;
                }
            }
            std::cout << cost << std::endl;
        }
    }
};
