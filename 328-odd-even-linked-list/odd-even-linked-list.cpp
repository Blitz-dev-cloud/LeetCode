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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;

        ListNode* oddList = head;
        ListNode* evenList = head->next;
        ListNode *p = oddList, *q = evenList;
        ListNode* curr = head->next->next;
        bool isOdd = true;

        while(curr) {
            if(isOdd) {
                p->next = curr;
                p = p->next;
            } else {
                q->next = curr;
                q = q->next;
            }
            curr = curr->next;
            isOdd = !isOdd;
        }

        q->next = nullptr;
        p->next = evenList;
        return oddList;
    }
};