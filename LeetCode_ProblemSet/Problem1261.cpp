#include <unordered_set>
#include <queue>
#include <functional>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class FindElements {
private:
    std::unordered_set<int> nodes;

public:
    FindElements(TreeNode* root) {
        std::queue<std::pair<TreeNode*, int>> q;
        root->val = 0;
        nodes.insert(0);
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, val] = q.front();
            q.pop();

            if (node->left != nullptr) {
                node->left->val = 2 * val + 1;
                q.push({node->left, node->left->val});
                nodes.insert(2 * val + 1);
            }

            if (node ->right != nullptr) {
                node->right->val = 2 * val + 2;
                q.push({node->right, node->right->val});
                nodes.insert(2 * val + 2);
            }
        }
    }
    
    bool find(int target) {
        return nodes.find(target) != nodes.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */