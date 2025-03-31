impl Solution {
    pub fn put_marbles(weights: Vec<i32>, k: i32) -> i64 {
        let mut costs = vec![0; weights.len() - 1 as usize];
        for idx in 0..weights.len() - 1 {
            costs[idx] = weights[idx] + weights[idx + 1];
        }
        costs.sort();

        let mut answer: i64 = 0;
        for i in 0..k as usize - 1 {
            answer += costs[costs.len() - 1 - i] as i64 - costs[i] as i64;
        }
        return answer;
    }
}