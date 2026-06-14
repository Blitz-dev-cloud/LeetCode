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
class Solution {
public:
    int pairSum(ListNode* head) {
        int i = 0;
        ListNode* r = head;
        
        stack<ListNode* > st;

        while(r->next) {
            st.push(r);
            r = r->next;
            i++;
        }

        int j = 0;
        ListNode* l = head;

        int sum = INT_MIN;

        while(j <= i) {
            cout << l->val << " " << r->val << endl;
            sum = max(sum, l->val + r->val);
            i--;
            j++;
            l = l->next;
            r = st.top();
            st.pop();
        }

        return sum;
    }
};