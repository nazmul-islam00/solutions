package main

import "math"

func secondMinimum(n int, edges [][]int, time int, change int) int {
	adj := get_adj(n, edges)
	dist := get_dist(n, adj)
	return get_time(dist, time, change)
}

func get_time(dist int, time int, change int) int {
	cur_time := 0

	for range dist {
		turn := int(math.Floor(float64(cur_time) / float64(change)))

		if turn % 2 == 0 {
			cur_time += time
		} else {
			cur_time = (turn + 1) * change + time
		}
	}

	return cur_time
}

func get_adj(n int, edges [][]int) [][]int {
	adj := make([][]int, n)
	for i := range adj {
		adj[i] = []int{}
	}

	for i := range edges {
		city_1, city_2 := edges[i][0]-1, edges[i][1]-1
		adj[city_1] = append(adj[city_1], city_2)
		adj[city_2] = append(adj[city_2], city_1)
	}

	return adj
}

func get_dist(n int, adj [][]int) int {
	dist := make([][]int, n)
	for i := range dist {
		dist[i] = []int{-1, -1}
	}
	dist[0][0] = 0

	queue := [][]int{}
	queue = append(queue, []int{0, 0})

	for len(queue) > 0 {
		city, dis := queue[0][0], queue[0][1]
		queue = queue[1:]

		for idx := range adj[city] {
			neighbor := adj[city][idx]

			if dist[neighbor][0] == -1 {
				dist[neighbor][0] = dis + 1
				queue = append(queue, []int{neighbor, dis + 1})

			} else if dist[neighbor][1] == -1 {
				if dist[neighbor][0] != dis+1 {
					dist[neighbor][1] = dis + 1
				}

				queue = append(queue, []int{neighbor, dis + 1})
			}
		}
	}

	return dist[n-1][1]
}