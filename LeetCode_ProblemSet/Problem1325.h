//
// Created by HP on 5/17/2024.
//

#ifndef PROBLEM1325_H
#define PROBLEM1325_H



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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root->left != nullptr) root->left = removeLeafNodes(root->left, target);
        if(root->right != nullptr) root->right = removeLeafNodes(root->right, target);
        if(root->left == nullptr && root->right == nullptr && root->val == target) return nullptr;
        return root;
    }
};



#endif //PROBLEM1325_H
