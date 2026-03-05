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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head; 
        ListNode* grpPrev = &dummy;

        while(true) {
            ListNode* kth = grpPrev;

            for( int i = 0 ; i < k && kth ; i++ ) kth = kth->next;

            if(!kth) break;

            ListNode* grpNext = kth->next;
            ListNode* prev = grpNext;
            ListNode* curr = grpPrev->next;

            while(curr != grpNext) {
                ListNode* newNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = newNode;
            }

            ListNode* temp = grpPrev->next;
            grpPrev->next = kth;
            grpPrev = temp;
        }

        return dummy.next;    
    }
};