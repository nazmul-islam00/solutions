#include <queue>
#include <vector>
#include <algorithm>

class MedianFinder {
    std::priority_queue<int, std::vector<int>, std::greater<int>> 
    minHeap;
    std::priority_queue<int> maxHeap;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (this->maxHeap.empty() || num <= this->maxHeap.top()) {
            this->maxHeap.push(num);
        } else {
            this->minHeap.push(num);
        }

        if (this->maxHeap.size() > this->minHeap.size() + 1) {
            this->minHeap.push(this->maxHeap.top());
            this->maxHeap.pop();
        } else if (this->minHeap.size() > this->maxHeap.size()) {
            this->maxHeap.push(this->minHeap.top());
            this->minHeap.pop();
        }
    }
    
    double findMedian() {
        if (this->maxHeap.size() > this->minHeap.size()) {
            return double(this->maxHeap.top());
        }
        return (this->maxHeap.top() + this->minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */