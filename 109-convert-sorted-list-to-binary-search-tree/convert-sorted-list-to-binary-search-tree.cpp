/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* curr;
    TreeNode* build(int l, int r) {
        if(l > r) return nullptr;

        int mid = l + (r - l) / 2;

        TreeNode* leftChild = build(l, mid - 1);

        TreeNode* root = new TreeNode(curr->val);
        root->left = leftChild;

        curr = curr->next;
        root->right = build(mid + 1, r);

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        curr = head;

        int n = 0;
        ListNode* temp = curr;
        while(temp) {
            n++;
            temp = temp->next;
        }

        return build(0, n - 1);
    }
};