impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        let mut left_max = vec![0; n];
        let mut right_max = vec![0; n];
        for j in 1..n {
            left_max[j] = std::cmp::max(left_max[j - 1], nums[j - 1]);
            right_max[n - 1 - j] = std::cmp::max(right_max[n - j], nums[n - j]);
        }
        let mut answer = 0;
        for j in 1..(n - 1) {
            answer = std::cmp::max(
                answer,
                (left_max[j] - nums[j]) as i64 * right_max[j] as i64
            );
        }
        return answer;
    }
}