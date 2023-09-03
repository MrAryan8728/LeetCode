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
    ListNode *detectCycle(ListNode *head) {
        ListNode *hare,*torto;
        hare = torto = head;
        while(hare and hare->next){
            torto = torto->next;
            hare = hare->next->next;
            if(hare == torto) break;
        }
        if(!(hare and hare->next)) return NULL;
        hare = head;
        while(hare != torto){
            hare = hare->next;
            torto = torto->next;
        }
        return hare;
    }
};