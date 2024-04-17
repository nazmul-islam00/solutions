#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

class Solution {
public:
    void run() {
        int n;
        std::cin >> n;
        /*
        * {watched, {start, end}}
        */
        std::vector<std::pair<bool, std::pair<int,int>>> s(n);
        for(int i = 0; i < n; i++)
            std::cin >> s[i].second.first >> s[i].second.second;
        std::sort(s.begin(), s.end(), [](auto s1, auto s2) {
            return s1.second.second < s2.second.second;
        });
        int watched = 0;
        int firstTVLastTime = -1, secondTVLastTime = -1;
        for(int i = 0; i < n; i++) {
            int firstTVIdleTime = s[i].second.first - firstTVLastTime;
            int secondTVIdleTime = s[i].second.first - secondTVLastTime;
            if(firstTVIdleTime <= 0 && secondTVIdleTime <= 0)
                break;
            if(firstTVIdleTime > 0 && secondTVIdleTime > 0) {
                int minIdleTime = std::min(firstTVIdleTime, secondTVIdleTime);
                // assign to the one most recently finished
                if(minIdleTime == firstTVIdleTime) {
                    firstTVLastTime = s[i].second.second;
                    s[i].first = true;
                } else {
                    secondTVLastTime = s[i].second.second;
                    s[i].first = true;
                
                }
                watched++;
            } else if(firstTVIdleTime > 0) {
                firstTVLastTime = s[i].second.second;
                s[i].first = true;
                watched++;
            } else {
                secondTVLastTime = s[i].second.second;
                s[i].first = true;
                watched++;
            }
        }
        if(watched == n) 
            std::cout << "YES" << std::endl;
        else 
            std::cout << "NO" << std::endl;
    }
};

int main() {
    Solution main;
    main.run();
}