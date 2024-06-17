#include <unordered_map>
#include<cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        // always possible
        if(c < 2) {
            return true;
        }
        unordered_map<int, int> prime_factors;
        int sq = sqrt(c);

        // reduce to odd number
        while(c % 2 == 0) {
            c /= 2;

            if(prime_factors.find(2) == prime_factors.end()) {
                prime_factors[2] = 1;
            } else {
                prime_factors[2] = prime_factors[2] + 1;
            }
        }

        // find odd factors
        for(int i = 3; i <= sq; i += 2) {

            while(c % i == 0) {

                if(prime_factors.find(i) == prime_factors.end()) {
                    prime_factors[i] = 1;
                } else {
                    prime_factors[i] = prime_factors[i] + 1;
                }
            }
        }

        // remaining is a prime
        if(c > 2) {
            prime_factors[c] = 1;
        }

        // check if prime factor of form 4k + 3 have even powers
        for(auto prime_factor : prime_factors) {
            
            if((prime_factor.first - 3) % 4 == 0 && prime_factor.second % 2) {
                return false;
            }  
        }

        return true;
    }
};