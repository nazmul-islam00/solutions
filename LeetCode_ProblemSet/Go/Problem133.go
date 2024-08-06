package main

type Node struct {
	Val       int
	Neighbors []*Node
}

func cloneGraph(node *Node) *Node {
	// empty graph
	if node == nil {
		return nil
	}
	// single node
	if len(node.Neighbors) == 0 {
		return &Node{
			Val: 1,
		}
	}

	return clone(node)
}

func clone(node *Node) *Node {
	nodes := map[int]*Node{
		1: {
			Val: 1,
		},
	}
	linksVisited := map[int]map[int]bool{
		1: {},
	}
	queue := []*Node{
		node,
	}
	
	for len(queue) > 0 {
		curNode := queue[0]
		queue = queue[1:]

		for _, neighbor := range curNode.Neighbors {
			if neighborNode, ok := nodes[neighbor.Val]; ok {
				if !linksVisited[curNode.Val][neighbor.Val] {
					linksVisited[curNode.Val][neighbor.Val] = true
					linksVisited[neighbor.Val][curNode.Val] = true
					node1 := nodes[curNode.Val]
					node1.Neighbors = append(node1.Neighbors, neighborNode)
					neighborNode.Neighbors = append(neighborNode.Neighbors, node1)
				}

			} else {
				nodes[neighbor.Val] = &Node{
					Val: neighbor.Val,
				}
				linksVisited[neighbor.Val] = map[int]bool{
					curNode.Val: true,
				}
				linksVisited[curNode.Val][neighbor.Val] = true
				node1, node2 := nodes[curNode.Val], nodes[neighbor.Val]
				node1.Neighbors = append(node1.Neighbors, node2)
				node2.Neighbors = append(node2.Neighbors, node1)
				queue = append(queue, neighbor)
			}
		}
	}

	return nodes[1]
}