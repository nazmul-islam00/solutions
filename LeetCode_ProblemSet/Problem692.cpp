#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <functional>

class Solution {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
        std::unordered_map<std::string, int> map;
        std::priority_queue<std::string, std::vector<std::string>, std::function<bool(const std::string&, const std::string&)>> heap(
            [&map](const std::string& p1, const std::string& p2) {
                if (map[p1] > map[p2]) {
                    return true;
                }
                if (map[p1] == map[p2] && p1 < p2) {
                    return true;
                }
                return false;
            }
        );
        std::vector<std::string> answer(k);
        for (std::string word : words) {
            map[word]++;
        }
        for (auto p : map) {
            if (heap.size() < k) {
                heap.push(p.first);
                continue;
            }
            if (p.second >= map[heap.top()]) {
                heap.push(p.first);
                heap.pop();
            }
        }
        for (int i = 0; i < k; i++) {
            answer[k - 1 - i] = heap.top();
            heap.pop();
        }
        return answer;
    }
};