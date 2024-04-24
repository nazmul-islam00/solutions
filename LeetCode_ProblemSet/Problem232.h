#include <stack>

class MyQueue {
    std::stack<int> mainStack, sideStack;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        this->mainStack.push(x);
    }
    
    int pop() {
        while(this->mainStack.size() != 1) {
            this->sideStack.push(this->mainStack.top());
            this->mainStack.pop();
        }
        int poppedVal = this->mainStack.top();
        this->mainStack.pop();
        while(!this->sideStack.empty()) {
            this->mainStack.push(this->sideStack.top());
            this->sideStack.pop();
        }
        return poppedVal;
    }
    
    int peek() {
        while(this->mainStack.size() != 1) {
            this->sideStack.push(this->mainStack.top());
            this->mainStack.pop();
        }
        int peekVal = this->mainStack.top();
        while(!this->sideStack.empty()) {
            this->mainStack.push(this->sideStack.top());
            this->sideStack.pop();
        }
        return peekVal;
    }
    
    bool empty() {
        return this->mainStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */