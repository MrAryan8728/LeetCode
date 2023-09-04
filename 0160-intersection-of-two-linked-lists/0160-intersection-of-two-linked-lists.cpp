/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 Hint:To find the intersection point of two linked lists, think about a way to make the two lists equal in length when starting from the head. What can you do to align them?
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0,len2 = 0;
        if(!headA or !headB) return NULL; 
        ListNode *temp1 = headA,*temp2 = headB;
        
        while(temp1){
            len1++;
            temp1 = temp1->next;
        }
        while(temp2){
            len2++;
            temp2 = temp2->next;
        }

        int skip = (len1 > len2)?len1-len2:len2-len1;

        if(len1 > len2){
            while(skip--){
                headA = headA->next;
            }
        }else{
            while(skip--){
                headB = headB->next;
            }
        }

        while(headA and headB){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};