import math


class Solution(object):
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        # always possible
        if c < 2:
            return True
        
        # find prime factorization
        prime_factors, sq = {}, math.sqrt(c)
        
        while c % 2 == 0:
            c //= 2
            
            if 2 in prime_factors:
                prime_factors[2] += 1
            else:
                prime_factors[2] = 1
                
        # now the number is odd
        i = 3
        while i <= sq:
            
            while c % i == 0:
                c //= i
                
                if i in prime_factors:
                    prime_factors[i] += 1
                else:
                    prime_factors[i] = 1
                    
            i += 2
            
        # remaining is a prime
        if c > 2:
            prime_factors[c], c = 1, 1
                
        # if any prime factor of form 4k + 3, doesn't have even power then not possible
        for prime in list(prime_factors.keys()):
            
            if (prime - 3) % 4 == 0 and prime_factors[prime] % 2 != 0:
                return False
            
        return True
                