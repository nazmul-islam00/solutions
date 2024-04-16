#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void run() {
        int len;
        std::cin >> len;
        std::string l, r;
        std::cin >>  l >> r;
        std::vector<std::pair<char, int>> left, right, leftWildCards, rightWildCards;
        // adding non-wildcard characters to left and right vectors
        // storing counts of wildcard characters
        for(int i = 0; i < len; i++) {
            if(l[i] != '?')
                left.push_back(std::make_pair(l[i], i + 1));
            else
                leftWildCards.push_back(std::make_pair(l[i], i + 1));
            if(r[i] != '?')
                right.push_back(std::make_pair(r[i], i + 1));
            else 
                rightWildCards.push_back(std::make_pair(r[i], i + 1));
        }
        // sorting left and right vectors in descending lexicograhic order
        std::sort(left.begin(), left.end(), [](auto p1, auto p2) {
            return p1.first > p2.first;
        });
        std::sort(right.begin(), right.end(), [](auto p1, auto p2) {
            return p1.first > p2.first;
        });
        std::vector<std::pair<char, int>> leftResidue;
        std::vector<std::pair<char, int>> rightResidue;
        std::vector<std::pair<int, int>> answer;
        int leftIndex = 0, rightIndex = 0;
        //  matching non-wildcard characters
        // storing ignored ones in residues
        while(leftIndex < left.size() && rightIndex < right.size()) 
            if(left[leftIndex].first == right[rightIndex].first) 
                answer.push_back(std::make_pair(left[leftIndex++].second, right[rightIndex++].second));
            else if(left[leftIndex].first > right[rightIndex].first) 
                leftResidue.push_back(left[leftIndex++]);
            else 
                rightResidue.push_back(right[rightIndex++]);
        // remaining characters are added to residues
        while(leftIndex < left.size()) 
            leftResidue.push_back(left[leftIndex++]);
        while(rightIndex < right.size()) 
            rightResidue.push_back(right[rightIndex++]);
        leftIndex = rightIndex = 0;
        // matching with wildcard characters
        // storing counts of remaining wildcard characters
        while(leftIndex < leftResidue.size() && rightIndex < rightWildCards.size()) 
            answer.push_back(std::make_pair(leftResidue[leftIndex++].second, rightWildCards[rightIndex++].second));
        int usedRightWildCards = rightIndex;
        leftIndex = rightIndex = 0;
        while(leftIndex < leftWildCards.size() && rightIndex < rightResidue.size()) 
            answer.push_back(std::make_pair(leftWildCards[leftIndex++].second, rightResidue[rightIndex++].second));
        int usedLeftWildCards = leftIndex;
        // making wildcard pairs
        while(leftIndex < leftWildCards.size() && rightIndex < rightWildCards.size()) 
            answer.push_back(std::make_pair(leftWildCards[leftIndex++].second, rightWildCards[rightIndex++].second));
        std::cout << answer.size() << std::endl;
        for(auto p : answer) 
            std::cout << p.first << " " << p.second << std::endl;
    }
};