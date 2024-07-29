package main

func numTeams(rating []int) int {
    count := getCount(rating)
	return getTeams(count)
}

func getTeams(count [][]int) int {
	teams := 0

	for idx := range count {
		teams += count[idx][0] * count[idx][3]
		teams += count[idx][1] * count[idx][2]
	}

	return teams
}

func getCount(rating []int) [][]int {
	count := make([][]int, len(rating))
	for idx := range rating {
		count[idx] = []int {0, 0, 0, 0}
	}

	for idx := range rating {
		cur, lesser, greater := 0, 0, 0

		for cur < idx {
			if rating[cur] < rating[idx] {
				lesser++
			} else {
				greater++
			}
			cur++
		}

		count[idx][0], count[idx][1] = lesser, greater
		lesser, greater = 0, 0
		cur++

		for cur < len(rating) {
			if rating[cur] < rating[idx] {
				lesser++
			} else {
				greater++
			}
			cur++
		}
		count[idx][2], count[idx][3] = lesser, greater
	}

	return count
}