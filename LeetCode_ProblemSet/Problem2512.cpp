#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <unordered_set>
#include <functional>
#include <algorithm>

class Compare {
public:
    bool operator()(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
        if (p1.first == p2.first) {
            return p1.second < p2.second;
        }
        return p1.first > p2.first;
    }
};

class Solution {
    int getPoints(const std::string& feedback, const std::unordered_set<std::string>& positive_words, const std::unordered_set<std::string>& negative_words) {
        std::stringstream ss(feedback);
        std::string word;
        int points = 0;

        while (ss >> word) {
            if (negative_words.find(word) != negative_words.end()) {
                points--;
            } else if (positive_words.find(word) != positive_words.end()) {
                points += 3;
            }
        }
        return points;
    }

public:
    std::vector<int> topStudents(std::vector<std::string>& positive_feedback, std::vector<std::string>& negative_feedback, std::vector<std::string>& report, std::vector<int>& student_id, int k) {
        std::unordered_set<std::string> positive_words(positive_feedback.begin(), positive_feedback.end());
        std::unordered_set<std::string> negative_words(negative_feedback.begin(), negative_feedback.end());
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> heap;
        std::vector<int> answer;
        answer.reserve(k);

        for (int i = 0; i < student_id.size(); i++) {
            heap.push({this->getPoints(report[i], positive_words, negative_words), student_id[i]});
            if (heap.size() > k) {
                heap.pop();
            }
        }

        for (int i = 0; i < k; i++) {
            answer.emplace_back(heap.top().second);
            heap.pop();
        }
        std::reverse(answer.begin(), answer.end());

        return answer;
    }
};