//
// Created by HP on 4/16/2024.
//

#ifndef PROBLEM623_H
#define PROBLEM623_H



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void addNode(TreeNode* root, int val, int depth, int currDepth) {
        if(root == nullptr) return;
        if(depth == currDepth + 1) {
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
            return;
        } else {
            addNode(root->left, val, depth, currDepth + 1);
            addNode(root->right, val, depth, currDepth + 1);
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) return root = new TreeNode(val, root, nullptr);
        addNode(root, val, depth, 1);
        return root;
    }
};


#endif //PROBLEM623_H
