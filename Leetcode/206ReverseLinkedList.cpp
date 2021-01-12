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


/*
Iterative
*/

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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL or !head->next)return head;
        if(!head->next->next){
            ListNode* temp = head->next;
            head->next=NULL;
            temp->next = head;
            return temp;
        }

            ListNode* prev = NULL,*curr = head, *Next1 = curr->next,*Next2 = Next1->next;
            while(Next2){
                ListNode* temp = curr;
                curr ->next = prev;

                prev = curr;
                curr = Next1;
                Next1 = Next2;
                Next2=Next2->next;
            }
        curr->next = prev;
        Next1->next = curr;

        return Next1;
    }
};
