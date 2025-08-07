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
private:
    vector<vector<int>> result;
    void dfs(TreeNode* node, int targetSum, vector<int> &path, int currSum) {
        if(!node) return;

        currSum += node->val;
        path.push_back(node->val);

        if(!node->left && !node->right && currSum == targetSum) result.push_back(path);

        dfs(node->left, targetSum, path, currSum);
        dfs(node->right, targetSum, path, currSum);

        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path, 0);
        return result;
    }
};