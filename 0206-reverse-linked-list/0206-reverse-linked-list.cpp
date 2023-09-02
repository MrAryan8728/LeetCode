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

//Don't forget to dry run on your own.
/* 
H->4->5->6->N

prev = head par 
curr = head ka next = phla value

jab tak curr null na ho 
next = curr ka next to safe ho jaayega
curr ka agla prev kar do link reverse ho jaayega 

Ab update krlo 
prev = curr par le aao 
curr = next par le aao

last me head ka next null krdena nhi to phle ko hi point krega 
Aur phir update krna prev se kyonki curr to NULL ho gya naa.

Note: Don't forget to handle the case of head and head ka next null hai to.
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode *prev = head;
        ListNode *curr = head->next;

        while(curr){
            ListNode *nxt = curr->next;
            curr->next = prev;

            //UPDATE
            prev = curr;
            curr = nxt;
        }
        head->next = NULL;
        head = prev;

        return head;
    }
};