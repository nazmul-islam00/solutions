//
// Created by HP on 4/16/2024.
//

#ifndef PROBLEM94_H
#define PROBLEM94_H
#include <vector>


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
    void inOrderTraversalHelp(std::vector<int>& answer, TreeNode* root) {
        if(root->left != nullptr) inOrderTraversalHelp(answer, root->left);
        answer.push_back(root->val);
        if(root->right != nullptr) inOrderTraversalHelp(answer, root->right);
    }
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> answer;
        if(root == nullptr) return answer;
        inOrderTraversalHelp(answer, root);
        return answer;
    }
};


#endif //PROBLEM94_H
