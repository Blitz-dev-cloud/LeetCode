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

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = nullptr;
        while(slow) {
            ListNode* newNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = newNode;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while(second) {
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next; 
        }

        return true;
    }
};