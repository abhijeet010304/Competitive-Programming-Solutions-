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
o(N*K)
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or !head->next)return head;
        int count = k;
        bool firstrev =false;
        ListNode *temp = head,*prev = NULL,*retstart=NULL,*end = NULL,*start = head;
        while(temp){
            end = temp;
            count --;
            temp =temp ->next;
            if(count==0){
                retstart = reversell(start,temp,end);

                if(!firstrev){
                    head = retstart;
                    firstrev = true;
                }
                else{
                    prev ->next = retstart;
                }
                end->next = temp;
                start = temp ;
                prev = end;
                count = k;
            }

        }
        return head;
    }

    ListNode* reversell(ListNode* start,ListNode*temp,ListNode* &end){
        if(!start or !start->next)return start;
        end = start;
        ListNode* prev = NULL,*curr = start,*Next = curr->next;
        while(Next!=temp){
            curr->next = prev;
            prev = curr;
            curr = Next;
            Next =Next->next;
        }
        curr->next = prev;

        return curr;
    }
};
