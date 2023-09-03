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
    //Hare and Tortotoise approach:
    bool hasCycle(ListNode *head) {
        ListNode *hare,*torto;
        hare = torto = head;
        while(hare and hare->next){
            torto = torto->next;
            hare = hare->next->next;
            if(hare == torto) return true;
        }
        return false;
    }
};