#include <vector>
#include <queue>
#include <functional>

using namespace std;


class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxAbility = 0;
        
        for(int ability : worker) {
            maxAbility = max(maxAbility, ability);
        }

        vector<int> maxProfit(maxAbility + 1, 0);

        for(int i = 0; i < difficulty.size(); i++) {
            if(difficulty[i] <= maxAbility) {
                maxProfit[difficulty[i]] = max(maxProfit[difficulty[i]], profit[i]);
            }
        }

        int currMaxProfit = 0;

        for(int i = 0; i < maxProfit.size(); i++) {
            maxProfit[i] = currMaxProfit = max(maxProfit[i], currMaxProfit);
        }

        int netProfit = 0;

        for(int i = 0; i < worker.size(); i++) {
            netProfit += maxProfit[worker[i]];
        }
        
        return netProfit;
    }
};