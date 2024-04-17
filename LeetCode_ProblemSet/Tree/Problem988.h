#include <algorithm>
#include <string>
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
    void getStrings(std::vector<std::string>& str, TreeNode* root, std::string s) {
        if(root == nullptr)
            return;
        s += root->val +97;
        if(root->left == nullptr && root->right == nullptr)
            str.push_back(s);
        getStrings(str, root->left, s);
        getStrings(str, root->right, s);
    }
public:
    std::string smallestFromLeaf(TreeNode* root) {
        std::string s ="";
        if(root == nullptr)
            return s;
        std::vector<std::string> str;
        getStrings(str, root, s);
        for(int i = 0; i < str.size(); i++)
            std::reverse(str[i].begin(), str[i].end());
       std:: sort(str.begin(), str.end());
        return str[0];
    }
};