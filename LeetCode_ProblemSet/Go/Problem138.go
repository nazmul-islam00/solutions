package main

// type Node struct {
// 	Val     int
// 	Next   *Node
// 	Random *Node
// }

func copyRandomList(head *Node) *Node {
	if head == nil {
		return nil
	}
	return copy(head)
}

func copy(head *Node) *Node {
	headNode := head
	nodes := map[*Node]*Node{}

	for {
		if head == nil {
			break
		}
		nodes[head] = &Node{
			Val: head.Val,
		}
		head = head.Next
	}

	for ogNode := range nodes {
		nodes[ogNode].Next = nodes[ogNode.Next]
		nodes[ogNode].Random = nodes[ogNode.Random]
 	}

	return nodes[headNode]
}