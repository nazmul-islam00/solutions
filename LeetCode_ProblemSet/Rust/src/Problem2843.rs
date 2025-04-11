impl Solution {
    pub fn count_symmetric_integers(low: i32, high: i32) -> i32 {
        let mut cnt = 0;
        for num in low..(high + 1) {
            let s = num.to_string();
            if s.len() % 2 == 1 {
                continue;
            }
            let mut sum = 0;
            for idx in 0..(s.len() / 2) {
                sum += s.chars().nth(idx).unwrap() as i32;
            }
            for idx in (s.len() / 2)..s.len() {
                sum -= s.chars().nth(idx).unwrap() as i32;
            }
            if sum == 0 {
                cnt += 1;
            }
        }
        return cnt;
    }
}