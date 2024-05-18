//
// Created by HP on 5/18/2024.
//

#ifndef PROBLEM979_H
#define PROBLEM979_H
#include <cmath>


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
};

class Solution {
    int getMoves(TreeNode* root, int& cnt) {
        // no moves required for non-existent nodes
        if(root == nullptr) return 0;
        // for each node consider the number of coins it lacks or needs o pass
        // this will be counted as moves
        // sum the value of current node's val with its left and right children
        // keep 1 for the node itself
        // if the value is negative it means that the node has deficit
        // else the node has extra coins it needs to move up
        // as this is a post order traversal, coins are only pushed up
        int moves = root->val + getMoves(root->left, cnt) + getMoves(root->right, cnt) - 1;
        // add the absolute value of moves to cnt
        cnt += std::abs(moves);
        return moves;
    }
public:
    int distributeCoins(TreeNode* root) {
        int cnt = 0;
        getMoves(root, cnt);
        return cnt;
    }
};



#endif //PROBLEM979_H
