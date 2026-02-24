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
    int dfs(TreeNode* root, int curr) {
        if(!root) return 0;
        
        curr = (curr << 1) | root->val;

        if(!root->left && !root->right) {
            return curr;
        }

        return dfs(root->left, curr) + dfs(root->right, curr);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};