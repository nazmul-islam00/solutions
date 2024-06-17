import java.util.HashMap;
import java.lang.Math;


class Solution {
    public boolean judgeSquareSum(int c) {
        // always possible
        if(c < 2) {
            return true;
        }

        HashMap<Integer, Integer> prime_factors = new HashMap<>();
        int sq = (int)Math.sqrt(c);

        // reduce to odd number
        while(c % 2 == 0) {
            c /= 2;

            if(!prime_factors.containsKey(2)) {
                prime_factors.put(2, 1);
            } else {
                prime_factors.put(2, prime_factors.get(2) + 1);
            }
        }

        // find prime factors
        for(int i = 3; i <= sq; i += 2) {
            while(c % i == 0) {
                c /= i;

                if(!prime_factors.containsKey(i)) {
                    prime_factors.put(i, 1);
                } else {
                    prime_factors.put(i, prime_factors.get(i) + 1);
                }
            }
        }

        // remaining is a prime
        if(c > 2) {
            prime_factors.put(c, 1);
        }

        // check if all prime factors of the form 4k + 3 have even powers
        for(int key : prime_factors.keySet()) {
            
            if((key - 3) % 4 == 0 && prime_factors.get(key) % 2 != 0) {
                return false;
            }
        }
 
        return true;
    }
}