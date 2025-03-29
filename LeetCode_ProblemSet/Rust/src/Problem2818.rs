use std::{collections::BinaryHeap, cmp::min};

impl Solution {
    const MOD: i32 = 1_000_000_007;

    pub fn maximum_score(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();

        let mut prime_scores = vec![0; n as usize];
        for idx in 0..n {
            let mut num = nums[idx];

            let mut fact = 2;
            while fact <= (num as f64).sqrt() as i32 {
                if num % fact == 0 {
                    prime_scores[idx] += 1
                }

                while num % fact == 0 {
                    num /= fact;
                }

                fact += 1;
            }
            
            if num >= 2 {
                prime_scores[idx] += 1;
            }
        }

        let mut next_dominant = vec![n as i32; n as usize];
        let mut prev_dominant = vec![-1; n as usize];
        let mut st: Vec<i32> = Vec::new();

        for idx in 0..n {
            while let Some(&top) = st.last() {
                if prime_scores[top as usize] < prime_scores[idx] {
                    next_dominant[top as usize] = idx as i32;
                    st.pop();
                } else {
                    break;
                }
            }

            if let Some(&top) = st.last() {
                prev_dominant[idx] = top;
            }

            st.push(idx as i32);
        }

        let mut num_of_subarrays = vec![0 as i128; n as usize];
        for idx in 0..n {
            num_of_subarrays[idx] = (next_dominant[idx] - idx as i32) as i128 * (idx as i32 - prev_dominant[idx]) as i128;
        }

        let mut pq: BinaryHeap<(i32, usize)> = BinaryHeap::new();
        for idx in 0..n {
            pq.push((nums[idx], idx));
        }

        let (mut cnt, mut score) = (k, 1);
        while cnt > 0 {
            if let Some((num, idx)) = pq.pop() {
                let ops = min(cnt as i128,num_of_subarrays[idx]);

                score = score * Self::power(num as i128, ops)  % Self::MOD as i128;
                cnt -= ops as i32;
            }
        }

        return score as i32;
    }

    fn power(base: i128, exp: i128) -> i128 {
        let mut res = 1;

        let (mut _exp, mut _base) = (exp, base);
        while _exp > 0 {
            if _exp % 2 == 1 {
                res = (res * _base) % Self::MOD as i128;
            }

            _base = (_base * _base) % Self::MOD as i128;
            _exp /= 2;
        }

        return res;
    }
}