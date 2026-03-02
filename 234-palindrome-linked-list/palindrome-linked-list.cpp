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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        ListNode *fast = head, *slow = head;
        stack<int> st;

        while(fast && fast->next) {
            st.push(slow->val);
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if(fast) slow = slow->next;

        while(slow) {
            if(slow->val == st.top()) {
                st.pop();
            } else return false;
            slow = slow->next;
        }

        return true;
    }
};