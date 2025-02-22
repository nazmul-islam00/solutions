#include <stack>
#include <string>
#include <functional>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* recoverFromPreorder(std::string traversal) {
        std::stack<std::pair<TreeNode*, int>> st;

        int idx = 0, val = 0;
        while (idx < traversal.size() && traversal[idx] != '-' ) {
            val *= 10;
            val += traversal[idx++] - '0';
        }

        TreeNode* root = new TreeNode(val);
        st.push({root, 0});

        while (idx  < traversal.size()) {
            int depth = 0;
            while (traversal[idx] == '-') {
                depth++;
                idx++;
            }

            int val = 0;
            while (idx < traversal.size() && traversal[idx] != '-' ) {
                val *= 10;
                val += traversal[idx++] - '0';
            }

            while (depth <= st.top().second) st.pop();

            TreeNode* newNode = new TreeNode(val);
            if (st.top().first->left == nullptr) st.top().first->left = newNode;
            else st.top().first->right = newNode;

            st.push({newNode, depth}); 
        }

        return root;
    }
};