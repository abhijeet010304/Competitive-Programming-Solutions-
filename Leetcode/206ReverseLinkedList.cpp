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
/*
Recursive Approach
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* end = head;
        head = reversell(head,end);
        return head;
    }
     ListNode* reversell( ListNode* start, ListNode* &end){
         if(!start or !start->next)return start;
         if(!start->next->next){
             ListNode* temp = start->next;
             start->next = NULL;
             temp->next = start;
             end = start;
             return temp;
         }

         ListNode* temp2 = reversell(start->next,end);

         end->next = start;
         start ->next = NULL;
         end = start;
         return temp2;
     }
};
