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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int length = 0;

        while(p){
            length++;
            p = p->next;
        }

        if(length <= 1) return nullptr;

        int steps = length - n;

        if(steps == 0) return head->next;

        ListNode* r = nullptr, *q = head;
        for(int i = 0; i < steps; i++){
            r = q;
            q = q->next;
        }
        
        r->next = q->next;
        return head; 
    }
};
