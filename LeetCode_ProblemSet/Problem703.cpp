#include <queue>
#include <vector>

class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<int>> scores;
    int k;

   public:
    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            this->add(num);
        }
    }

    int add(int val) {
        if (this->scores.size() < this->k || val > this->scores.top()) {
            this->scores.push(val);   
        }
        if (this->scores.size() > k) {
            this->scores.pop();
        }
        return this->scores.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */