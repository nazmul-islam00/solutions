//
// Created by HP on 5/1/2024.
//

#ifndef PROBLEM1172_H
#define PROBLEM1172_H
#include <stack>
#include <vector>


class DinnerPlates {
    int capacity;
    int leftMostNonFull;
    int rightMostNonEmpty;
    std::vector<std::stack<int>> stacks;
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
        this->leftMostNonFull = 0;
        this->rightMostNonEmpty = -1;
        std::stack<int> st;
        stacks.push_back(st);
    }

    void push(int val) {
        this->stacks[this->leftMostNonFull].push(val);
        if(this->leftMostNonFull > this->rightMostNonEmpty) {
            this->rightMostNonEmpty = this->leftMostNonFull;
        }
        if(this->stacks[this->leftMostNonFull].size() == this->capacity) {
            while(this->leftMostNonFull < this->stacks.size()) {
                if(this->stacks[this->leftMostNonFull].size() < this->capacity) {
                    break;
                }
                this->leftMostNonFull++;
            }
            if(this->leftMostNonFull == this->stacks.size()) {
                std::stack<int> st;
                this->stacks.push_back(st);
            }
        }
    }

    int pop() {
        if(this->rightMostNonEmpty == -1 || this->stacks[this->rightMostNonEmpty].empty()) {
            return -1;
        }
        int val = this->stacks[this->rightMostNonEmpty].top();
        this->stacks[this->rightMostNonEmpty].pop();
        if(this->leftMostNonFull > this->rightMostNonEmpty) {
            this->leftMostNonFull = this->rightMostNonEmpty;
        }
        if(this->stacks[this->rightMostNonEmpty].empty()) {
            while(this->rightMostNonEmpty >= 0) {
                if(!this->stacks[this->rightMostNonEmpty].empty()) {
                    break;
                }
                this->rightMostNonEmpty--;
            }
        }
        return val;
    }

    int popAtStack(int index) {
        if(index >= this->stacks.size() || this->stacks[index].empty()) {
            return -1;
        }
        if(index < this->leftMostNonFull) {
            this->leftMostNonFull = index;
        }
        int val = this->stacks[index].top();
        this->stacks[index].pop();
        if(this->stacks[index].empty() && this->rightMostNonEmpty == index) {
            while(this->rightMostNonEmpty >= 0) {
                if(!this->stacks[this->rightMostNonEmpty].empty()) {
                    break;
                }
                this->rightMostNonEmpty--;
            }
        }
        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */



#endif //PROBLEM1172_H
