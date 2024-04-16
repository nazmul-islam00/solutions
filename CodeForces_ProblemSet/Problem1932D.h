#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    std::vector<std::pair<std::string, std::string>> getPairs
    (std::vector<std::string>& trump, std::vector<std::string>& suite1, 
    std::vector<std::string>& suite2, std::vector<std::string>& suite3) {
        std::vector<std::pair<std::string, std::string>> answer;
        int suite1Index = 0, suite2Index = 0, suite3Index = 0, trumpIndex = 0;
        // matching within non-trump suites 
        while(suite1Index + 1 <suite1.size()) 
            answer.push_back({suite1[suite1Index++], suite1[suite1Index++]});
        while(suite2Index + 1 <suite2.size())
            answer.push_back({suite2[suite2Index++], suite2[suite2Index++]});
        while(suite3Index + 1 <suite3.size()) 
            answer.push_back({suite3[suite3Index++], suite3[suite3Index++]});
        // mtahcing non-trump suites with trump suites
        while(suite1Index < suite1.size() && trumpIndex < trump.size())
            answer.push_back({suite1[suite1Index++], trump[trumpIndex++]});
        while(suite2Index < suite2.size() && trumpIndex < trump.size())
            answer.push_back({suite2[suite2Index++], trump[trumpIndex++]});
        while(suite3Index < suite3.size() && trumpIndex < trump.size())
            answer.push_back({suite3[suite3Index++], trump[trumpIndex++]});
        //matching within trump suite
        while(trumpIndex + 1 < trump.size())
            answer.push_back({trump[trumpIndex++], trump[trumpIndex++]});
        return answer;
    }
public:
    void run() {
        int t;
        std::cin >> t;
        while(t--) {
            int n;
            char trump;
            std::vector<std::string> c, d, h, s;
            std::cin >> n >> trump;
            for(int i = 0; i < 2 * n; i++) {
                std::string in;
                std::cin >> in;
                // segregating cards based on suite
                switch(in[1]) {
                    case 'C': c.push_back(in); break;
                    case 'D': d.push_back(in); break;
                    case 'H': h.push_back(in); break;
                    case 'S': s.push_back(in); break;
                }
            }
            // sorting cards according to rank
            std::sort(c.begin(), c.end());
            std::sort(d.begin(), d.end());
            std::sort(h.begin(), h.end());
            std::sort(s.begin(), s.end());
            std::vector<std::pair<std::string, std::string>> answer;
            // calling helper function based on trump
            switch(trump) {
                case 'C': answer = getPairs(c, d, h, s); break;
                case 'D': answer = getPairs(d, c, h, s); break;
                case 'H': answer = getPairs(h, c, d, s); break;
                case 'S': answer = getPairs(s, c, d, h); break;
            }
            if(answer.size() < n) {
                std::cout << "IMPOSSIBLE" <<std::endl;
            } else {
                for(auto p : answer) 
                std::cout << p.first << " " << p.second <<std::endl;
            }
        }
    }
};
