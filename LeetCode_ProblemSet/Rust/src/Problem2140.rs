impl Solution {
    pub fn most_points(questions: Vec<Vec<i32>>) -> i64 {
        let n = questions.len();
        let mut points = vec![-1 as i64; n];
        points[n - 1] = questions[n - 1][0] as i64;
        for idx in (0..(n - 1)).rev() {
            let mut next = 0;
            if questions[idx][1] as usize + idx + 1 < n {
                next = points[questions[idx][1] as usize + idx + 1];
            }
            points[idx] = std::cmp::max(questions[idx][0] as i64 + next, points[idx + 1])
        }
        return points[0];
    }
}