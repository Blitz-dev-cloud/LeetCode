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
    void dfs(TreeNode* root, bool isLeft, int &sum) {
        if(!root) return;

        if(!root->left && !root->right && isLeft) {
            sum += root->val;
            return;
        }

        dfs(root->left, true, sum);
        dfs(root->right, false, sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        dfs(root, false, sum);
        return sum;
    }
};