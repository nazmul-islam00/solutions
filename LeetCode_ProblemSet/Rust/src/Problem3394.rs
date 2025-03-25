use std::cmp::max;

impl Solution {
    pub fn check_valid_cuts(_: i32, rectangles: Vec<Vec<i32>>) -> bool {
        let mut x_coords: Vec<(i32, i32)> = rectangles.iter().map(|r| (r[0], r[2])).collect();
        let mut y_coords: Vec<(i32, i32)> = rectangles.iter().map(|r| (r[1], r[3])).collect();

        x_coords.sort();
        y_coords.sort();

        for coords in vec![x_coords, y_coords] {
            let (mut cnt, mut cur) = (0, 0);
            for (start, end) in coords {
                if start < cur {
                    cur = max(cur, end);
                    continue;
                } 
                cnt += 1;
                if cnt == 3 {
                    return true;
                }
                cur = end;
            }
        }

        return false;
    }
}