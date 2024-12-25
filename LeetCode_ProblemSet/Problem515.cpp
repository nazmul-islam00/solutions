#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};

        std::vector<int> answer;
        std::queue<std::pair<TreeNode*, int>> bfsQueue;
        bfsQueue.push({root, 0});
        std::pair<int, int> currMax = {root->val, 0};

        while (!bfsQueue.empty()) {
            std::pair<TreeNode*, int> curr = bfsQueue.front();
            bfsQueue.pop();

            if (curr.second != currMax.second) {
                answer.push_back(currMax.first);
                currMax = {curr.first->val, curr.second};
            } else {
                currMax = {std::max(currMax.first, curr.first->val), curr.second};
            }

            if (curr.first->left != nullptr) bfsQueue.push({curr.first->left, curr.second + 1});
            if (curr.first->right != nullptr) bfsQueue.push({curr.first->right, curr.second + 1});
        }

        answer.push_back(currMax.first);
        return answer;
    }
};