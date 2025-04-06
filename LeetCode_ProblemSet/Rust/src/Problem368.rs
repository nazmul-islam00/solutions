impl Solution {
    pub fn largest_divisible_subset(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();

        let mut num_with_indices: Vec<(i32, usize)> = nums
            .iter()
            .enumerate()
            .map(|(idx, &num)| (num, idx))
            .collect();
        num_with_indices.sort();

        let mut opt = vec![0; n];
        let mut parent = vec![n; n];
        opt[num_with_indices[0].1] = 1;

        for i in 1..n {
            let (num1, idx1) = num_with_indices[i];

            for j in 0..i {
                let (num2, idx2) = num_with_indices[j];
                if num1 % num2 != 0 {
                    continue;
                }
                if opt[idx2] + 1 > opt[idx1] {
                    opt[idx1] = 1 + opt[idx2];
                    parent[idx1] = idx2;
                }
            }

            if opt[idx1] == 0 {
                opt[idx1] = 1;
            }
        }

        let (mut max_idx, mut max_size) = (n, 0);
        for i in 0..n {
            if opt[i] > max_size {
                max_size = opt[i];
                max_idx = i;
            }
        }

        let mut answer = Vec::new();
        let mut cur_idx = max_idx;
        while cur_idx != n {
            answer.push(nums[cur_idx]);
            cur_idx = parent[cur_idx];
        }

        return answer;
    }
}
