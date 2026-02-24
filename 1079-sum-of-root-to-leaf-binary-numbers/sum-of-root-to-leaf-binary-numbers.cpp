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
    int sum = 0;
    string s = "";
    void dfs(TreeNode* root) {
        if(!root) return;
        s += char(root->val + '0');
        if(!root->left && !root->right) {
            int num = 0;

            for( char c : s ) {
                num = num * 2 + (c - '0');
            }

            sum += num;
        } else{
            dfs(root->left);
            dfs(root->right);
        }
        s.pop_back();
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root);
        return sum;
    }
};