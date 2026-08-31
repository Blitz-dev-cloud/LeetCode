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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> indices;

        ListNode* tail = head;
        if(!tail) return {-1, -1};

        ListNode* ptr = tail->next;
        if(!ptr) return {-1, -1};

        ListNode* nxt = ptr->next;
        if(!nxt) return {-1, -1};

        // ptr = ptr->next;
        int idx = 1;

        while(ptr && nxt) {
            if((ptr->val < tail->val && ptr->val < nxt->val) || (ptr->val > tail->val && ptr->val > nxt->val)) {
                indices.push_back(idx);
            }

            tail = tail->next;
            ptr = ptr->next;
            nxt = nxt->next;
            
            idx++;
        }

        int n = indices.size();

        if(n == 0) return {-1, -1};

        int maxDistance = indices[n - 1] - indices[0];

        int minDist = INT_MAX;
        for( int i = 1 ; i < n ; i++ ) {
            int diff = indices[i] - indices[i - 1];
            minDist = min(minDist, diff);
        }

        if(minDist == INT_MAX) return {-1, -1};

        return {minDist, maxDistance};
    }
};