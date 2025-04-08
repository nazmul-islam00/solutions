use std::collections::HashSet;

impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut set = HashSet::new();
        for i in (0..n).rev() {
            if !set.contains(&nums[i]) {
                set.insert(nums[i]);
            } else {
                return ((i + 1) as f32 / 3.0).ceil() as i32;
            }
        }
        return 0;
    }
}