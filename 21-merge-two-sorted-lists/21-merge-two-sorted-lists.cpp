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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)return list2;
        if(!list2)return list1;
        ListNode* start = NULL, *last = NULL, *h1  = list1, *h2 = list2;
        if(!start and !last and h1->val<=h2->val){
            start = h1;
            last = h1;
            h1 = h1->next;
        
        }else {
                start = h2;
                last = h2;
                h2 = h2->next;
            
        
        }
        while(h1 and h2){
            
           
            if(h1->val<=h2->val){
                last->next = h1;
                last = h1;
                h1 = h1->next;
            }else{

                last->next = h2;
                last = h2;
                h2 = h2->next;   
            }

        }
        while(h1){
            last->next = h1;
            last = h1;
            h1 = h1->next;
        }
        while(h2){
            last->next = h2;
            last = h2;
            h2 = h2->next;
        }
        return start;
    }
};