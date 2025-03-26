impl Solution {
    pub fn min_operations(grid: Vec<Vec<i32>>, x: i32) -> i32 {
        let mut nums: Vec<i32> = vec![];
        for row in grid {
            for num in row {
                nums.push(num);
            }
        }

        nums.sort();
        let (mut cost, median) = (0, nums[nums.len() / 2]);
        for num in nums {
            if (median - num) % x != 0 {
                return -1;
            }

            if median > num {
                cost += (median - num) / x;
            } else {
                cost += (num - median) / x;
            }
        }
        return cost;
    }
}