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
    int maxPath = INT_MIN;
    int findPath(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = max(0, findPath(root->left));
        int rh = max(0, findPath(root->right));

        maxPath = max(maxPath, root->val + lh + rh);

        return root->val + max(lh, rh);
    }
public:
    int maxPathSum(TreeNode* root) {
        findPath(root);
        return maxPath;
    }
};