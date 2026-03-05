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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* curr = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;

        while(curr) {
            ListNode* newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while(second) {
            ListNode *a = first->next, *b = second->next;

            first->next = second;
            second->next = a;

            first = a, second = b;
        }
    }
};