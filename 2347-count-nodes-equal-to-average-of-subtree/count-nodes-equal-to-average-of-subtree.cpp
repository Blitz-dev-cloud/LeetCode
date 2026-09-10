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
    unordered_map<TreeNode* , pair<int, int>> store;
    int ans = 0;

    void dfs(TreeNode* root) {
        if(!root->left && !root->right) {
            ans++;
            store[root] = {root->val, 1};
            return;
        }

        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);

        pair p1 = {0, 0};
        pair p2 = {0, 0};

        if(store.count(root->left)) p1 = store[root->left];
        if(store.count(root->right)) p2 = store[root->right];

        int v1 = p1.first, c1 = p1.second;
        int v2 = p2.first, c2 = p2.second;

        int avg = (root->val + v1 + v2) / (c1 + c2 + 1);

        if(avg == root->val) ans++;

        store[root] = {root->val + v1 + v2, c1 + c2 + 1};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        /* queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()) {
            auto p = q.front();
            q.pop();


        } */
        dfs(root);
        return ans;
    }
};