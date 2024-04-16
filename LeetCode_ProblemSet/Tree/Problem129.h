//
// Created by HP on 4/15/2024.
//

#ifndef PROBLEM129_H
#define PROBLEM129_H
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
    int answer;
    void getPaths(TreeNode* node, std::vector<int>& path, int depth) {
        if(!node) return;
        path[depth++] = node->val;
        if(!node->left && !node->right) updateAnswer(path, depth);
        else {
            getPaths(node->left, path, depth);
            getPaths(node->right, path, depth);
        }
    }
    void updateAnswer(std::vector<int>& path, int depth) {
        int sum = 0;
        for(int i = 0; i < depth; i++) {
            sum *= 10;
            sum += path[i];
        }
        this->answer += sum;
    }
public:
    Solution() {answer = 0;}
    int sumNumbers(TreeNode* root) {
        std::vector<int> path(10, 0);
        getPaths(root, path, 0);
        return this->answer;
    }
};



#endif //PROBLEM129_H
