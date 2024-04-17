#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    void run() {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        std::unordered_map<int, int> boxers;
        for(int i = 0; i < n; i++) 
            std::cin >> a[i];
        std::sort(a.begin(), a.end());
        int ans = 0;
        for(int i = 0; i < n; i++) 
            if(a[i] - 1 != 0 && boxers.find(a[i] - 1) == boxers.end())
                boxers[a[i] - 1] = ans++;
            else if(boxers.find(a[i]) == boxers.end())
                boxers[a[i]] = ans++;
            else if(boxers.find(a[i] + 1) == boxers.end())
                boxers[a[i] + 1] = ans++;
        std::cout << ans << std::endl;
    }
};
