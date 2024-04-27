//
// Created by HP on 4/27/2024.
//

#ifndef PROBLEM114_H
#define PROBLEM114_H
#include <stack>
#include <vector>


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

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
    void flatten(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }
        std::vector<int> vals;
        std::stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* temp = s.top();
            s.pop();
            vals.push_back(temp->val);
            if(temp->right != nullptr) {
                s.push(temp->right);
            }
            if(temp->left != nullptr) {
                s.push(temp->left);
            }
        }
        TreeNode* temp = root;
        for(int i = 1; i < vals.size(); i++) {
            temp->left = nullptr;
            temp = temp->right = new TreeNode(vals[i]);
        }
    }
};



#endif //PROBLEM114_H
