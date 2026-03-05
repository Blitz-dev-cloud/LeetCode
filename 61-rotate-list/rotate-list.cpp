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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return 0;
        ListNode* curr = head;
        ListNode* prev = head;
        int cnt = 1;

        while(curr->next) {
            cnt++;
            curr = curr->next;
        }
        curr->next = head;
        k = k% cnt;
        int count = cnt - k;

        while(count-- > 1) {
            prev = prev->next;
        }
        ListNode* temp = prev;
        temp = temp->next;

        prev->next = nullptr;
        //cout << cnt << endl;

        return temp;
    }
};