impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let mut sum = 0;
        for &num in &nums {
            sum += num;
        }
        if sum % 2 != 0 {
            return false;
        }

        let target = sum / 2;
        let mut dp = vec![false; (target + 1) as usize];
        dp[0] = true;
        for &num in &nums {
            for i in (num..(target + 1)).rev() {
                if dp[(i - num) as usize] {
                    dp[i as usize] = true;
                }
            }
        }
        return dp[target as usize];
    }
}
