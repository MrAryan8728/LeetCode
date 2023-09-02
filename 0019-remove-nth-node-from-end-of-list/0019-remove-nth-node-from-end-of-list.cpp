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
 //Previous solution:
//Complexity : O(2n)xO(1)
 /*     int size = 1;
        ListNode *temp = head;
        while(temp->next){
            temp = temp->next;
            size++;
        }

        if(size == 1 and n == 1) return NULL;

        if(size == n){
             head = head->next;
             return head;
        }
        
        int it = size-n;
        temp = head;
        while(it > 1){
            temp = temp->next;
            it--;
        }
        // cout<<temp->val;
        if(temp->next) temp->next = temp->next->next;
        return head;
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *f = head,*s = head;
        while(n--){
            f = f->next;
        }

        if(!f) return head->next;

        while(f->next){
            f = f->next;
            s = s->next;
        }

        if(s->next) s->next = s->next->next;
        return head;
    }
};