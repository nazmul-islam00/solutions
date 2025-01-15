class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitsCnt1 = countSetBits(num1), setBitsCnt2 = countSetBits(num2);

        if (setBitsCnt2 == 0) return 0;
        if (setBitsCnt2 == setBitsCnt1) return num1;

        int num = num1;
        if (setBitsCnt2 < setBitsCnt1) {
            int resetCnt = setBitsCnt1 - setBitsCnt2;

            for (int i = 0; i < 32; i++) {
                if ((num & (1 << i)) > 0) {
                    resetCnt--;
                    num = num ^ (1 << i);
                }
                if (resetCnt == 0) break;
            }
        } else {
            int setCnt = setBitsCnt2 - setBitsCnt1;

            for (int i = 0; i < 32; i++) {
                if ((num & (1 << i)) == 0) {
                    setCnt--;
                    num = num ^ (1 << i);
                }
                if (setCnt == 0) break;
            }
        }

        return num;
    }

private:
    int countSetBits(int num) {
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            cnt += (num & (1 << i)) > 0;
        }
        return cnt;
    }
};