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
    vector<TreeNode*> generate(int start, int end) {
        if(start > end) return {nullptr};

        vector<TreeNode*> result;

        for( int root = start ; root <= end ; root++ ) {
            auto leftTrees = generate(start, root - 1);
            auto rightTrees = generate(root + 1, end);

            for( auto left : leftTrees ) {
                for( auto right : rightTrees ) {
                    TreeNode* node = new TreeNode(root);

                    node->left = left;
                    node->right = right;

                    result.push_back(node);
                }
            }
        }

        return result;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};