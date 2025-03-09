/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head){
        return head;
    }

    struct ListNode* p = head, *q = NULL;

    while(p->next != NULL){
        if(p->val == (p->next)->val){
            int val = p->val;
            struct ListNode* r;
            if(!q){
                while(p && p->val == val){
                    struct ListNode* q = head;
                    head = head->next;
                    p = p->next;
                    free(q);
                }
            }
            else{
                while(p && p->val == val){
                    r = p;
                    p = p->next;
                    q->next = p;
                    free(r);
                }
            }
            if(!p){
                break;
            }
        }
        else{
            q = p;
            p = p->next;
        }
    }

    return head;
}