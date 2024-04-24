#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class Solution {
public:
    void run() {
        int n, l;
        std::cin >> n >> l;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        long double distFromStart = a[0] - 0;
        long double distFromEnd = l - a[n-1];
        long double maxPairDist = 0;
        for(int i = 0; i < n - 1; i++) {
            maxPairDist = std::max(maxPairDist, (long double)(a[i+1] - a[i]));
        }
        maxPairDist /= 2;
        long double ans = std::max({distFromStart, distFromEnd, maxPairDist});
        std::cout << std::setprecision(10) << ans << std::endl;
    }
};

int main() {
    Solution main;
    main.run();
}