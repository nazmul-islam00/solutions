class Solution {
public:
    int minimumSum(int n, int k) {
        int sum = 0, curr = 1, cnt = 0;
        while (cnt < n) {
            if (curr < k && k - curr < curr) {
                curr++;
                continue;
            }
            sum += curr++;
            cnt++;
        }
        return sum;
    }
};