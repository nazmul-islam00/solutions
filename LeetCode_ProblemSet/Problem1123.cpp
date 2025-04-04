#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   private:
    int depths[1001];
    TreeNode* answer;

   public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxDepth = getMaxDepth(root);
        (void) getLca(root, maxDepth);
        return answer;
    }

   private:
    int getMaxDepth(TreeNode* root, int curDepth = -1) {
        if (root == nullptr) return curDepth;
        
        depths[root->val] = curDepth + 1;
        return std::max(
            getMaxDepth(root->left, curDepth + 1),
            getMaxDepth(root->right, curDepth + 1));
    }

    bool getLca(TreeNode* root, int maxDepth) {
        if (root == nullptr) return false;

        bool left = getLca(root->left, maxDepth);
        bool right = getLca(root->right, maxDepth);

        if (depths[root->val] == maxDepth) {
            answer = root;
            return true;
        }
        if (left && right) {
            answer = root;
            return true;
        }

        if (left || right) return true;
        return false;
    }
};