impl Solution {
    const MOD: i64 = 1_000_000_007;

    pub fn count_good_numbers(n: i64) -> i32 {
        let even = (n + 1) / 2;
        let odd = n - even;
        let ans = Solution::binary_exp(5, even) * Solution::binary_exp(4, odd);
        return (ans % Solution::MOD) as i32;
    }

    fn binary_exp(a: i64, b: i64) -> i64 {
        if b == 0 {
            return 1;
        }
        let res = Solution::binary_exp(a, b / 2) % Solution::MOD;
        let sq = (res * res) % Solution::MOD;
        if b % 2 == 1 {
            return (sq * a) % Solution::MOD;
        }
        return sq;
    }
}