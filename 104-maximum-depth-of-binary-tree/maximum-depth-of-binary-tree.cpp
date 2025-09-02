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
public:
    int maxDepth(TreeNode* root) {
        if(!root) return NULL;
        
        queue<pair<TreeNode* , int>> q;
        q.push({root, 1});
        int mh = 1;

        while(!q.empty()) {
            auto [node, height] = q.front();
            mh = max(mh, height);

            q.pop();

            if(node->left) q.push({node->left, height + 1});
            if(node->right) q.push({node->right, height + 1});
        }

        return mh;
    }
};