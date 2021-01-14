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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1  = 0,l2 = 0;
        ListNode *temp = headA;
        while(temp){
            l1++;
            temp = temp->next;
        }
        temp = headB;
        while(temp){
            l2++;
            temp = temp ->next;
        }
        if(l1<l2){
            int dif  = l2-l1;
            ListNode *p1 = headA,*p2 = headB;
            while(dif--){
                p2 = p2->next;
            }
            while(p1 and p2 and p1!=p2){
                p1 = p1->next;
                p2 = p2->next;

            }
            p1 = p2;
            return p1;
        }
        else{
            int dif  = l1-l2;
            ListNode *p1 = headA,*p2 = headB;
            while(dif--){
                p1 = p1->next;
            }
            while(p1 and p2 and p1!=p2){
                p1 = p1->next;
                p2 = p2->next;

            }
            p1 = p2;
            return p1;
        }

    }

};
