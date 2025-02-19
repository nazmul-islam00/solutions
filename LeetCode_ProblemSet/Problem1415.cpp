#include <string>
#include <vector>
#include <algorithm>


class Solution {
public:
    std::string getHappyString(int n, int k) {
        // std::vector<std::string> happyStrings;
        // std::string choice = "";

        // generateHappyStrings(n, happyStrings, choice);
        // if (happyStrings.size() < k) return "";

        // std::sort(happyStrings.begin(), happyStrings.end());
        // return happyStrings[k - 1];

        if (k > (3 * (1 << (n - 1)))) return "";

        std::string answer(n, 'a');
        std::vector<char> smallest = {'b', 'a', 'a'};
        std::vector<char> greatest = {'c', 'c', 'b'};

        int startA = 1, startB = startA + (1 << (n - 1)), startC = startB + (1 << (n - 1));

        if (k < startB) {
            answer[0] = 'a';
            k -= startA;
        } else if (k < startC) {
            answer[0] = 'b';
            k -= startB;
        } else {
            answer[0] = 'c';
            k -= startC;
        }

        for (int idx = 1; idx < n; idx++) {
            int mid = (1 << (n - idx - 1));

            if (k < mid) answer[idx] = smallest[answer[idx - 1 - 'a']];
            else {
                answer[idx] = greatest[answer[idx - 1 - 'a']];
                k -= mid;
            }
        }

        return answer;
    }

private:
    void generateHappyStrings(int n, std::vector<std::string>& happyStrings, std::string& curr) {
        if (curr.size() == n) {
            happyStrings.push_back(curr);
            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (curr.size() > 0 && curr[curr.size() - 1] == ch) continue;

            curr += ch;
            generateHappyStrings(n, happyStrings, curr);

            curr = curr.substr(0, curr.size() - 1);
        }
    }
};