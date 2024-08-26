package main

/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func postorder(root *Node) []int {
	nodes := []int{}
	postorderHelp(root, &nodes)
	return nodes
}

func postorderHelp(root *Node, nodes *[]int) {
	if root == nil {
		return 
	}
	for _, child := range root.Children {
		postorderHelp(child, nodes)
	}
	*nodes = append(*nodes, root.Val)
}