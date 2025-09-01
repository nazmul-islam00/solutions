#include <vector>
#include <queue>
#include <functional>

class Solution {
public:
    double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents) {
        std::priority_queue<std::pair<double, int>> pq;
        for (int i = 0; i < classes.size(); i++) {
            double newRatio = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            double oldRatio = (double)classes[i][0] / classes[i][1];
            double gain = newRatio - oldRatio;
            pq.push({gain, i});
        }
        while (extraStudents--) {
            int i = pq.top().second;
            pq.pop();
            classes[i][0]++;
            classes[i][1]++;
            double newRatio = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            double oldRatio = (double)classes[i][0] / classes[i][1];
            double gain = newRatio - oldRatio;
            pq.push({gain, i});
        }
        double totalPassRatio = 0.0;
        for (auto& cls : classes) {
            totalPassRatio += (double)cls[0] / cls[1];
        }
        return totalPassRatio / classes.size();
    }
};