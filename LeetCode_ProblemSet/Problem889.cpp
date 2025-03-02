#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode* constructFromPrePost(std::vector<int>& preorder, std::vector<int>& postorder) {
        return construct(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }

   private:
   /*
    The value of the root node is the leftmost value in the preorder array and the right most value in the post order array
    The value of the left child is the second left most value in the preorder array
    The value of the right child is the second right most value in the postorder array
    If the two values above agree, then the node must have a single child, whether it is left or right cannot be determined from the information given so you are welcome to pick one or the other
    We can then split preorder into the root, a preorder of the left child, and a preorder of the right child
    We can then split postorder into a postorder of the left child, a postorder of the right child, and the root.
    Apply recursion!
   */
    TreeNode* construct(std::vector<int>& preorder, std::vector<int>& postorder, int preorderStart, int preorderEnd, int postorderStart, int postorderEnd) {
        // single node
        if (preorderStart == preorderEnd) return new TreeNode(preorder[preorderStart]);

        TreeNode* root = new TreeNode(preorder[preorderStart]);

        // single child
        if (preorderStart < preorder.size() - 1 && postorderEnd > 0 && preorder[preorderStart + 1] == postorder[postorderEnd - 1]) {
            root->left = construct(preorder, postorder, preorderStart + 1, preorderEnd, postorderStart, postorderEnd - 1);
            return root;
        }

        // two children
        int preorderLeftStart = preorderStart + 1, postorderRightEnd = postorderEnd - 1;
        int postorderRightStart = find(postorder.begin(), postorder.end(), preorder[preorderLeftStart]) - postorder.begin() + 1;
        int postorderLeftStart = postorderStart, postorderLeftEnd = postorderRightStart - 1;
        int preorderLeftEnd = preorderLeftStart + postorderLeftEnd - postorderLeftStart;
        int preorderRightStart = preorderLeftEnd + 1, preorderRightEnd = preorderEnd;

        root->left = construct(preorder, postorder, preorderLeftStart, preorderLeftEnd, postorderLeftStart, postorderLeftEnd);
        root->right = construct(preorder, postorder, preorderRightStart, preorderRightEnd, postorderRightStart, postorderRightEnd);

        return root;
    }
};