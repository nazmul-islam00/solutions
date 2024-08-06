package main

// type TreeNode struct {
// 	Val    int
// 	Left  *TreeNode
// 	Right *TreeNode
// }

func postorderTraversal(root *TreeNode) []int {
    nodes := []int{}
	postorder(root, &nodes)
	return nodes
}

func postorder(root *TreeNode, nodes *[]int) {
	if root == nil {
		return 
	}
	postorder(root.Left, nodes)
	postorder(root.Right, nodes)
	*nodes = append(*nodes, root.Val)
}