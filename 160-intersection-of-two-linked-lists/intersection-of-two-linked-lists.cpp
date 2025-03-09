/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //blitz
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        struct ListNode *p = headA;
        struct ListNode* q = headB;
        while(p != q){
            p = (!p) ? headA : p->next;
            q = (!q) ? headB : q->next;
        }
        return p;
    }
};