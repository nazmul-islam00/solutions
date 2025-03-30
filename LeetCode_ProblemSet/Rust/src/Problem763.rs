use std::cmp::max;

impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        let mut answer = Vec::new();
        let mut last_occurrences = [0; 26];

        for (idx, c) in s.chars().enumerate() {
            last_occurrences[c as usize - 'a' as usize] = idx;
        }

        let (mut start, mut end) = (0, 0);
        for (idx, c) in s.chars().enumerate() {
            end = max(end, last_occurrences[c as usize - 'a' as usize]);

            if idx == end {
                answer.push((end - start + 1) as i32);
                start = idx + 1;
            }
        }

        return answer;
    }
}