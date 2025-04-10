impl Solution {
    pub fn number_of_powerful_int(start: i64, finish: i64, limit: i32, s: String) -> i64 {
        return Solution::count(&finish.to_string(), &s, limit)
            - Solution::count(&(start - 1).to_string(), &s, limit);
    }

    fn count(finish: &str, s: &str, limit: i32) -> i64 {
        if finish.len() < s.len() {
            return 0;
        }
        if finish.len() == s.len() {
            if finish >= s {
                return 1;
            } else {
                return 0;
            }
        }

        let suffix = &finish[(finish.len() - s.len())..];
        let mut ans = 0;
        let prefix_len = finish.len() - s.len();

        for digit in 0..prefix_len {
            if limit < (finish.chars().nth(digit).unwrap() as i32 - '0' as i32) {
                ans += ((limit + 1) as i64).pow((prefix_len - digit) as u32) as i64;
                return ans;
            }
            ans += (finish.chars().nth(digit).unwrap() as i32 - '0' as i32) as i64 * ((limit + 1) as i64).pow((prefix_len - digit - 1) as u32) as i64;
        }
        if suffix >= s.clone() {
            ans += 1;
        }

        return ans;
    }
}
