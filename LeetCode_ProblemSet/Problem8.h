class Solution {
    const long long UPPER_LIMIT = 2147483648 - 1;
    const long long LOWER_LIMIT = -2147483648;
    bool isDigit(char c) {
        return c >= '0' && c<='9';
    }
public:
    int myAtoi(string s) {
        long long answer = 0;
        int i = 0;
        while(s[i] == ' ')
            i++;
        bool isNegative = false;
        if(s[i] == '+')
            i++;
        else if(s[i] == '-') {
            i++;
            isNegative = true;
        }
        for(; i < s.length(); i++) {
            if(!isDigit(s[i])) {
                break;
            }
            answer *= 10;
            answer += s[i] - '0';
            if(answer > UPPER_LIMIT && !isNegative) {
                answer = UPPER_LIMIT;
                break;
            } else if(answer > UPPER_LIMIT + 1 && isNegative) {
                answer = LOWER_LIMIT;
                isNegative = false;
                break;
            }
        }
        if(isNegative)
            answer *= -1;
        return answer;
    }
};