#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <functional>

class Solution {
private:
        // parse the string to get the integer value
        int getInt(std::string &str) {
            return 1000 * (str[0] - '0') + 100 * (str[1] - '0') + 10 * (str[2] - '0') + (str[3] - '0');
        }
        // get the previous lock sequence by changing the character at pos
        std::string getPrev(std::string& str, int pos) {
            std::string res = str;
            switch(res[pos]) {
                case '0': res[pos] = '9'; break;
                default : res[pos] = res[pos] - 1; break;
            }
            return res;
        }
        // get the next lock sequence by changing the character at pos
        std::string getNext(std::string& str, int pos) {
            std::string res = str;
            switch(res[pos]) {
                case '9': res[pos] = '0'; break;
                default : res[pos] = res[pos] + 1; break;
            }
            return res;
        }
public:
    int openLock(std::vector<std::string>& deadends, std::string target) {
        // match with initial sequence
        if(target == "0000") {
            return 0;
        }
        // deadends in unordered_map for quick lookups
        std::unordered_map<std::string, int> deadendMap;
        for(std::string s : deadends) {
            deadendMap[s] = 1;
        }
        // return -1 if target is in deadends
        if(deadendMap.find("0000") != deadendMap.end()) {
            return -1;
        }
        std::queue<std::pair<std::string, int>> bfsQueue;
        std::vector<bool> visited(10000, false);
        bfsQueue.push({"0000", 0});
        visited[0] = true;
        // bfs traversal
        while(!bfsQueue.empty()) {
            auto it = bfsQueue.front();
            bfsQueue.pop();
            std::string str = it.first;
            int distance = it.second;
            // check for previous sequences for pos 0 through 3
            for(int i = 0; i < 4; i++) {
                std::string str1 = getPrev(str, i);
                // check if in deadend
                if(deadendMap.find(str1) != deadendMap.end()) {
                    continue;
                }
                // check if already visited
                if(visited[getInt(str1)]) {
                    continue;
                }
                // return if target is reached
                if(str1 == target) {
                    return distance + 1;
                }
                bfsQueue.push({str1, distance + 1});
                visited[getInt(str1)] = true;
            }
            // check for next sequences for pos 0 through 3
            for(int i = 0; i < 4; i++) {
                std::string str1 = getNext(str, i);
                // check if in deadend
                if(deadendMap.find(str1) != deadendMap.end()) {
                    continue;
                }
                // check if already visited
                if(visited[getInt(str1)]) {
                    continue;
                }
                // return if target is reached
                if(str1 == target) {
                    return distance + 1;
                }
                bfsQueue.push({str1, distance + 1});
                visited[getInt(str1)] = true;
            }
        }
        // target was never reached
        return -1;
    }
};