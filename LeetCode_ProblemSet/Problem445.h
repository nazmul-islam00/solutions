//
// Created by HP on 4/30/2024.
//

#ifndef PROBLEM445_H
#define PROBLEM445_H



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    /*
     * return true if extra node is needed
     */
    bool add(ListNode* l1, ListNode* l2) {
        if(l1->next == nullptr && l2->next == nullptr) {
            int newVal = l1->val + l2->val;
            bool addNode = false;
            if(newVal > 9) {
                newVal %= 10;
                addNode = true;
            }
            l1->val = newVal;
            return addNode;
        }
        bool addNode = add(l1->next, l2->next);
        int newVal = l1->val + l2->val + addNode;
        addNode = false;
        if(newVal > 9) {
            addNode = true;
            newVal %= 10;
        }
        l1->val = newVal;
        return addNode;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0, n2 = 0;
        ListNode *temp1 = l1, *temp2 = l2;
        // count the number of nodes in both lists
        while(temp1 != nullptr) {
            n1++;
            temp1 = temp1->next;
        }
        while(temp2 != nullptr) {
            n2++;
            temp2 = temp2->next;
        }
        // if second list is lengthier just call the function with inverted params
        if(n1 < n2) {
            return addTwoNumbers(l2, l1);
        }
        /*
         * if the number of nodes  in equal ,
         * just add the numbers
         * & add extra node if needed
         */
        if(n1 == n2) {
            bool addNode = add(l1, l2);
            if(addNode) {
                ListNode* newNode = new ListNode(1, l1);
                l1 = newNode;
            }
            return l1;
        } else {
            /*
             * if the number of nodes is not equal
             * start from the node from which the rest has the same length as the other list
             * while traversing store the listNode pointers in a stack
             * while addNode is true,
             * keep changing values of the listNodes in the stack
             * add extra node if needed
             */
            int diff = n1 - n2;
            stack<ListNode*> listnodeStack;
            ListNode* startL1 = l1;
            for(int i = 0; i < diff; i++) {
                listnodeStack.push(startL1);
                startL1 = startL1->next;
            }
            bool addNode = add(startL1, l2);
            while(addNode && !listnodeStack.empty()) {
                ListNode* currNode = listnodeStack.top();
                listnodeStack.pop();
                int newVal = currNode->val + 1;
                if(newVal > 9) {
                    newVal %= 10;
                } else {
                    addNode = false;
                }
                currNode->val = newVal;
            }
            if(addNode) {
                ListNode* newNode = new ListNode(1, l1);
                l1 = newNode;
            }
            return l1;
        }
        return new ListNode();
    }
};



#endif //PROBLEM445_H
