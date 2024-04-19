#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    void run() {
        int t;
        std::cin >> t;
        while(t--) {
            int n;
            std::cin >> n;
            std::vector<int> a(n);
            for(int i = 0; i < n; i++) 
                std::cin >> a[i];
            std::unordered_map<int, int> map;
            for(int i = 0; i < n; i++) {
                auto it = map.find(a[i]);
                if(it == map.end())
                    map[a[i]] = 1;
                else 
                    it->second = it->second + 1;
            }
            std::vector<int> counts(map.size());
            for(int i = 0; i < counts.size(); i++) {
                counts[i] = map.begin()->second;
                map.erase(map.begin());
            }
            std::sort(counts.begin(), counts.end(), std::greater<int>());
            long long ans = 0;
            std::unordered_map<int, int> selected;
            for(int i = 0; i < counts.size(); i++) {
                auto it = selected.find(counts[i]);
                if(it == selected.end()) {
                    selected[counts[i]] = 1;
                    ans += counts[i];
                } else {
                    while(it != selected.end() && counts[i] > 0) {
                        counts[i]--;
                        it = selected.find(counts[i]);
                    }
                    if(counts[i] > 0) {
                        selected[counts[i]] = 1;
                        ans += counts[i];
                    }
                }
            }
            std::cout << ans << std::endl;
        }
    }
};

