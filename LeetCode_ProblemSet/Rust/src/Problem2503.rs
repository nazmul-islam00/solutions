use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    const CHANGE_X: [i32; 4] = [-1, 1, 0, 0];
    const CHANGE_Y: [i32; 4] = [0, 0, -1, 1];

    pub fn max_points(grid: Vec<Vec<i32>>, queries: Vec<i32>) -> Vec<i32> {
        let mut sorted_queries = Vec::new();
        for idx in 0..queries.len() {
            sorted_queries.push((queries[idx], idx));
        }
        sorted_queries.sort();

        let mut visited = vec![vec![false; grid[0].len()]; grid.len()];
        let mut pq = BinaryHeap::new();

        pq.push(Reverse((grid[0][0], 0, 0)));
        visited[0][0] = true;

        let mut cnt = 0;
        let mut answer = vec![0; queries.len()];
        for (query, idx) in sorted_queries {
            while let Some(Reverse((val, x, y))) = pq.pop() {
                if val >= query {
                    pq.push(Reverse((val, x, y)));
                    break;
                }

                cnt += 1;
                for idx in 0..Self::CHANGE_X.len() {
                    let (row, col) = (x + Self::CHANGE_X[idx], y + Self::CHANGE_Y[idx]);

                    if Self::is_in_grid(grid.len() as i32, grid[0].len() as i32, row, col) && !visited[row as usize][col as usize] {
                        visited[row as usize][col as usize] = true;
                        pq.push(Reverse((grid[row as usize][col as usize], row, col)));
                    }
                }
            }
            answer[idx] = cnt;
        }

        return answer
    }

    fn is_in_grid(m: i32, n: i32, row: i32, col: i32) -> bool {
        return 0 <= row && row < m && 0 <= col && col < n;
    }
}