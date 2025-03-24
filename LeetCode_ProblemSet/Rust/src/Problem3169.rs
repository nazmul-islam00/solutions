use std::cmp::max;

impl Solution {
    pub fn count_days(days: i32, meetings: Vec<Vec<i32>>) -> i32 {
        let (mut curStart, mut curEnd) = (0, 0);
        let mut count = 0;

        let mut meetings_copy = meetings;
        meetings_copy.sort();

        for meeting in meetings_copy {
            let (start, end) = (meeting[0], meeting[1]);

            if curStart <= start && start <= curEnd {
                curEnd = max(curEnd, end);
            } else {
                count += start - curEnd - 1;
                (curStart, curEnd) = (start, end);
            }
        }
        count += days - curEnd;

        return count;
    }
}