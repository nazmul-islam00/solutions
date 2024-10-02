#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    std::vector<int> rearrangeBarcodes(std::vector<int>& barcodes) {
        bool multiple = false;
        std::unordered_map<int, int> count;
        for (int barcode : barcodes) {
            auto barcodeCount = count.find(barcode);
            if (barcodeCount == count.end()) {
                count[barcode] = 1;
            } else {
                barcodeCount->second = barcodeCount->second + 1;
                multiple = true;
            }
        }

        if (!multiple) {
            return barcodes;
        }

        std::priority_queue<
            std::pair<int, int>,
            std::vector<std::pair<int, int>>
        > heap;
        for (auto& [key, value] : count) {
            heap.push({value,key});
        }
        
        std::vector<int> answer(barcodes.size(), 0);
        std::pair<int, int> p = heap.top();
        heap.pop();
        answer[0] = p.second;
        heap.push({p.first - 1, p.second});
        
        for (int i = 1; i < barcodes.size(); i++) {
            std::pair<int, int> p = heap.top();
            heap.pop();
            if (p.second != answer[i - 1]) {
                answer[i] = p.second;
                if (p.first == 1) {
                    continue;
                }
                heap.push({p.first - 1, p.second});
                continue;
            }
            std::pair<int, int> q = heap.top();
            heap.pop();
            answer[i] = q.second;
            heap.push(p);
            if (q.first == 1) {
                continue;
            }
            heap.push({q.first - 1, q.second});
        }
        return answer;
    }
};