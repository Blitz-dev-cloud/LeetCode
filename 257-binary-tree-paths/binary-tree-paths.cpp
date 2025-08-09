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
    void dfs(TreeNode*root, string curr, vector<string> &result) {
        if(!root) return;

        curr += to_string(root->val);

        if(!root->left && !root->right) {
            result.push_back(curr);
            return;
        }

        curr += "->";

        dfs(root->left, curr, result);
        dfs(root->right, curr, result);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};