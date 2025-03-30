use std::cmp::max;

impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        let mut answer: Vec<i32> = Vec::new();
        let mut first_occurrences = vec![-1 as i32; 26];
        let mut last_occurrences = vec![-1 as i32; 26];

        for idx in 0..s.len() {
            if first_occurrences[s.chars().nth(idx).unwrap() as usize - 'a' as usize] == -1 {
                first_occurrences[s.chars().nth(idx).unwrap() as usize - 'a' as usize] = idx as i32;
            }
            last_occurrences[s.chars().nth(idx).unwrap() as usize - 'a' as usize] = idx as i32;
        }

        let mut idx = 0;
        while idx < s.len() {
            let mut max_last =
                last_occurrences[s.chars().nth(idx).unwrap() as usize - 'a' as usize];
            let mut init_max;

            loop {
                init_max = max_last;
                for i in 0..26 {
                    if first_occurrences[i] < max_last {
                        max_last = max(max_last, last_occurrences[i]);
                    }
                }

                if max_last == init_max {
                    break;
                }
            }

            answer.push(max_last - idx as i32 + 1);
            idx = max_last as usize + 1;
        }

        return answer;
    }
}
