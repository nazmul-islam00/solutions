
#include <iostream>
#include <unordered_map>


class Solution {
public:
    void run() {
        int t;
        std::cin >> t;
        while(t--) {
            std::string s;
            std::cin >> s;
            long long res = 0;
            std::unordered_map<int, int> map;
            int curr = 0;
            for(int i = 0; i < s.length(); i++) {
                switch(s[i]) {
                    case '+': curr++; break;
                    case '-': curr--; break;
                }
                if(map.find(curr) == map.end())
                    map[curr] = i + 1;
            }
            curr = 0;
            while(true) {
                auto it = map.find(- curr - 1);
                if(it == map.end()) {
                    res += s.length();
                    break;
                }
                res += it->second;
                curr++;
            }
            std::cout << res << std::endl;
        }
    }
};

// int main() {
//     Solution main;
//     main.run();
// }

