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
        if(!root) return 0;
        
        queue<pair<int, TreeNode* >> q;
        q.push({1, root});

        int result = 0;

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            int height = p.first;
            TreeNode* node = p.second;

            result = max(result, height);

            if(node->left) q.push({height + 1, node->left});
            if(node->right) q.push({height + 1, node->right});
        }

        return result;
    }
};