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
    vector<int> inorder;

    void inorderTraversal(TreeNode* root) {
        if(!root) return;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }

    TreeNode* buildBalancedBST(int l, int r) {
        if(l > r) return nullptr;

        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);

        root->left = buildBalancedBST(l, mid - 1);
        root->right = buildBalancedBST(mid + 1, r);

        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal(root);
        return buildBalancedBST(0, inorder.size() - 1);
    }
};