#include <vector>
#include <queue>
#include <functional>


class Solution {
public:
    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph) {
        std::vector<std::vector<int>> incomingEdges(graph.size());
        std::vector<int> outDegree(graph.size());
        std::queue<int> q;
        std::vector<int> answer;
        answer.reserve(graph.size());

        for (int i = 0; i < graph.size(); i++) {
            outDegree[i] = graph[i].size();
            if (outDegree[i] == 0) q.push(i);

            for (int j = 0; j < graph[i].size(); j++) {
                incomingEdges[graph[i][j]].push_back(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int i = 0; i < incomingEdges[node].size(); i++) {
                outDegree[incomingEdges[node][i]]--;
                if (outDegree[incomingEdges[node][i]] == 0) q.push(incomingEdges[node][i]);
            }

            answer.push_back(node);
        }

        sort(answer.begin(), answer.end());
        return answer;
    }
};