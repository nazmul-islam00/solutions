/**
 * @param {number} c
 * @return {boolean}
 */
var judgeSquareSum = function(c) {
    // always possible
    if (c < 2) {
        return true;
    }

    const prime_factors = new Map();
    const sq = Math.floor(Math.sqrt(c));

    // reduce to odd number
    while (c % 2 === 0) {
        c /= 2;

        if (!prime_factors.has(2)) {
            prime_factors.set(2, 1);
        } else {
            prime_factors.set(2, prime_factors.get(2) + 1);
        }
    }

    // find prime factors
    for (let i = 3; i <= sq; i += 2) {
        while (c % i === 0) {
            c /= i;

            if (!prime_factors.has(i)) {
                prime_factors.set(i, 1);
            } else {
                prime_factors.set(i, prime_factors.get(i) + 1);
            }
        }
    }

    // remaining is a prime
    if (c > 2) {
        prime_factors.set(c, 1);
    }

    // check if all prime factors of the form 4k + 3 have even powers
    for (let key of prime_factors.keys()) {
        if ((key - 3) % 4 === 0 && prime_factors.get(key) % 2 !== 0) {
            return false;
        }
    }

    return true;
};
