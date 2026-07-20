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
    int result = 0;
    int dfs(TreeNode* root) {
        if(!root) return 0;

        int max1 = dfs(root->left);
        int max2 = dfs(root->right);

        int maxv = max({max1, max2, root->val});

        if(maxv == root->val) result++;

        return maxv;
    }
public:
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return result;
    }
};