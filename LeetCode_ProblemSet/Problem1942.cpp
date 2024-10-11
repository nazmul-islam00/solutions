#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

class Solution {
public:
    int smallestChair(std::vector<std::vector<int>>& times, int targetFriend) {
        // min priority queue to store the chairs with departure times
        std::priority_queue<
            std::pair<int, int>, 
            std::vector<std::pair<int, int>>, 
            std::function<bool(const std::pair<int, int>&, const std::pair<int, int>&)>
        > chairDepartures(
            [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
                if (p1.second == p2.second) {
                    return p1.first < p2.first;
                }
                return p1.second > p2.second;
            }
        );
        // min priority queue to store available chairs
        std::priority_queue<int, std::vector<int>, std::greater<int>> availableChairs;
        // arrival time of target friend
        int targetArrival = times[targetFriend][0];

        // sort the arrival times
        std::sort(times.begin(), times.end());
        // fill the available chairs heap
        for (size_t i = 0; i < times.size(); i++) {
            availableChairs.push(i);
        }

        for (const std::vector<int>& time : times) {
            // empty the departing ones & push to available
            while (!chairDepartures.empty() && chairDepartures.top().second <= time[0]) {
                availableChairs.push(chairDepartures.top().first);
                chairDepartures.pop();
            }

            // get the least available chair
            int chair = availableChairs.top();
            availableChairs.pop();

            // return if the target friend has arrived
            if (time[0] == targetArrival) {
                return chair;
            }

            // push to the departure queue
            chairDepartures.push({chair, time[1]});
        }

        return -1;
    }
};