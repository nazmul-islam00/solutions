#include <string>


class Solution {
public:
    /*
        if the string has length less than k, 
        then it is not possible to form k palindromes
        if the count of characters having odd counts is greater than k,
        then the count of palindromes must be greater than k
        as any palindrome can have at most 1 character with odd count
        else it is always possible to form the k palindromes
    */
    bool canConstruct(std::string s, int k) {
        if (s.size() < k) return false;
        bool isOdd[26];
        int cnt = 0;

        for (const char c : s) {
            isOdd[c - 'a'] = !isOdd[c - 'a'];
        }

        for (int i = 0; i < 26; i++) {
            cnt += isOdd[i];
        }

        return cnt <= k;
    }
};