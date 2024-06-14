class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, int> secretHolders;
        secretHolders[0] = secretHolders[firstPerson] = 1;
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(firstPerson);
        sort(meetings.begin(), meetings.end(), [](auto m1, auto m2) {
            return m1[2] < m2[2];
        });
        int currTime = meetings[0][2];
        int currTimeStartInd = 0;
        bool repeated = false;
        for(int i = 0; i < meetings.size(); i++) {
            auto it1 = secretHolders.find(meetings[i][0]);
            auto it2 = secretHolders.find(meetings[i][1]);
            if(it1 == secretHolders.end() && it2 != secretHolders.end()) {
                secretHolders[meetings[i][0]] = 1;
                ans.push_back(meetings[i][0]);
            } else if(it2 == secretHolders.end() && it1 != secretHolders.end()) {
                secretHolders[meetings[i][1]] = 1;
                ans.push_back(meetings[i][1]);
            }
            if(i + 1 < meetings.size() && meetings[i + 1][2] != currTime) {
                if(!repeated) {
                    repeated = true;
                    i = currTimeStartInd - 1;
                } else {
                    repeated = false;
                    currTime = meetings[i + 1][2];
                    currTimeStartInd = i + 1;
                }
            } else if(i + 1 == meetings.size() && !repeated) {
                repeated = true;
                i = currTimeStartInd - 1;
            }
        }
        return ans;
    }
};

/*
 * arrange all meetings according to person
 * for two src and time 0 run dfs
 * do so recursively
 * store visited data
 * count visited ones
*/



/*
unordered_map<int, int> secretHolders;
secretHolders[0] = secretHolders[firstPerson] = 1;
sort(meetings.begin(), meetings.end(), [](auto m1, auto m2) {
return m1[2] < m2[2];
});
vector<vector<int>> mergedMeetings;
vector<int> time1 = {meetings[0][0], meetings[0][1]};
mergedMeetings = {time1};
for(int i = 1; i < meetings.size(); i++) {
if(meetings[i - 1][2] != meetings[i][2]) {
vector<int> newTime = {meetings[i][0], meetings[i][1]};
mergedMeetings.push_back(newTime);
} else {
mergedMeetings[mergedMeetings.size() - 1].push_back(meetings[i][0]);
mergedMeetings[mergedMeetings.size() - 1].push_back(meetings[i][1]);
}
}
for(int i = 0; i < mergedMeetings.size(); i++) {
bool found = false;
for(int j = 0; j < mergedMeetings[i].size(); j++) {
auto it = secretHolders.find(mergedMeetings[i][j]);
if(it != secretHolders.end()) {
found = true;
break;
}
}
if(found) {
for(int j = 0; j < mergedMeetings[i].size(); j++) {
secretHolders[mergedMeetings[i][j]] = 1;
}
}
}
vector<int> ans;
for(auto it : secretHolders) {
ans.push_back(it.first);
}
return ans;
8/