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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head =NULL,*end=NULL;
        if(!l1 and !l2) return l1;
        if(!l1)return l2;
        if(!l2)return l1;
        while(l1 and l2){
            int val ;
            if(l1->val<l2->val){
                val = l1->val;
                l1=l1->next;
            }
            else{
                val = l2->val;
                l2=l2->next;
            }
            cout<<val<<" ";
            ListNode* temp = create(val);
            if(head==NULL){
                head = temp;
                end = temp;

            }
            else{
                end->next = temp;
                end=temp;
            }



        }
        while(l1){
             int val = l1->val;
            ListNode* temp = create(val);
            if(head==NULL){
                head = temp;
                end = temp;

            }
            else{
                end->next = temp;
                end=temp;
            }

            l1=l1->next;


        }
        while(l2){
             int val = l2->val;
            ListNode* temp = create(val);
            if(head==NULL){
                head = temp;
                end = temp;

            }
            else{
                end->next = temp;
                end = temp;
            }


            l2=l2->next;

        }
        return head;
    }
     ListNode* create(int val){
         ListNode* temp = new  ListNode;
         temp ->val = val;
         temp->next = NULL;
         return temp;

     }

};
