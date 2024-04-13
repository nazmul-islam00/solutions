//
// Created by HP on 4/12/2024.
//

#ifndef PROBLEM1019_H
#define PROBLEM1019_H
#include <queue>
#include <vector>


/*
  Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static std::vector<int> nextLargerNodes(ListNode* head) {
        std::vector<int> answer;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        int index = 0;
        while(head != nullptr) {
            answer.push_back(0);
            if(!pq.empty()) {
                while(!pq.empty() && pq.top().first < head->val) {
                    answer[pq.top().second] = head->val;
                    pq.pop();
                }
            }
            pq.push({head->val, index});
            index++;
            head = head->next;
        }
        return answer;
    }
};



#endif //PROBLEM1019_H
