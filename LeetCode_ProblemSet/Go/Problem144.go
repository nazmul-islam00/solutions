package main

// type TreeNode struct {
// 	Val    int
// 	Left  *TreeNode
// 	Right *TreeNode
// }

func preorderTraversal(root *TreeNode) []int {
    nodes := []int{}
	preorder(root, &nodes)
	return nodes
}

func preorder(root *TreeNode, nodes *[]int) {
	if root == nil {
		return 
	}
	*nodes = append(*nodes, root.Val)
	preorder(root.Left, nodes)
	preorder(root.Right, nodes)
}