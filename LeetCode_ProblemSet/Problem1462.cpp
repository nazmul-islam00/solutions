#include <vector>
#include <queue>


class Solution {
public:
    std::vector<bool> checkIfPrerequisite(int numCourses, std::vector<std::vector<int>>& prerequisites, std::vector<std::vector<int>>& queries) {
        std::vector<std::vector<bool>> isReachable = std::vector<std::vector<bool>>(numCourses, std::vector<bool>(numCourses, false));
        std::vector<std::vector<int>> adjacencyList = std::vector<std::vector<int>>(numCourses);
        std::vector<bool> result = std::vector<bool>(queries.size());


        for (const std::vector<int>& prerequisite : prerequisites) {
            adjacencyList[prerequisite[0]].push_back(prerequisite[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            std::queue<int> bfsQueue;
            bfsQueue.push(i);
            isReachable[i][i] = true;

            while (!bfsQueue.empty()) {
                int curr = bfsQueue.front();
                bfsQueue.pop();

                for (const int course : adjacencyList[curr]) {
                    if (isReachable[i][course]) continue;
                    bfsQueue.push(course);
                    isReachable[i][course] = true;
                }
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            result[i] = isReachable[queries[i][0]][queries[i][1]];
        }

        return result;
    }
};