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
    vector<int> res;
    void inorderTraversal(TreeNode* root) {
        if(!root) return;

        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorderTraversal(root);
        if(k <= res.size()) return res[k - 1];
        else return false;
    }
};