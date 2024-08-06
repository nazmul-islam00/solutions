package main

func intersection(nums1 []int, nums2 []int) []int {
    nums := map[int]bool{}
	commons := map[int]bool {}
	ans := []int{}
	for _, num := range nums2 {
		nums[num] = true
	}
	for _, num := range nums1 {
		if _, ok := nums[num]; ok {
			commons[num] = true
		}
	}
	for num := range commons {
		ans = append(ans, num)
	}
	return ans
}