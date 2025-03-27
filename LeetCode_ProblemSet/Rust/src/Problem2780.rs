use std::collections::HashMap;

impl Solution {
    pub fn minimum_index(nums: Vec<i32>) -> i32 {
        let mut freq: HashMap<i32, i32> = HashMap::new();
        for &num in &nums {
            *freq.entry(num).or_insert(0) += 1;
        }

        let (dominant_element, cnt) = freq.iter().max_by_key(|&(_, v)| v).unwrap();

        let mut pre: i32 = 0;
        for idx in 0..nums.len() - 1 {
            if nums[idx] == *dominant_element {
                pre += 1;
            }

            let dominant_left = pre > (idx as i32 + 1) / 2;
            let dominant_right = (cnt - pre) > (nums.len() - idx - 1) as i32 / 2;
            if dominant_left && dominant_right  {
                return idx as i32;
            }
        }

        return -1;
    }
}
