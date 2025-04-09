use std::collections::HashSet;

impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        let mut set = HashSet::new();
        for num in nums {
            if num < k {
                return -1;
            }
            if num > k {
                set.insert(num);
            }
        }
        return set.len() as i32;
    }
}