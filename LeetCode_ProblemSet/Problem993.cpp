#include <queue>
//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int parentX = -1, parentY = -1;
        int depthX = -1, depthY = -1;

        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            std::pair<TreeNode*, int> p = q.front();
            q.pop();

            if (p.first->val == x) {
                depthX = p.second;
            } else if (p.first->val == y) {
                depthY = p.second;
            }

            if (p.first->left != nullptr) {
                parentX = p.first->left->val == x ? p.first->val : parentX;
                parentY = p.first->left->val == y ? p.first->val : parentY;
                q.push({p.first->left, p.second + 1});
            }
            if (p.first->right != nullptr) {
                parentX = p.first->right->val == x ? p.first->val : parentX;
                parentY = p.first->right->val == y ? p.first->val : parentY;
                q.push({p.first->right, p.second + 1});
            }
        }
        return depthX == depthY && parentX != parentY;
    }
};