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
    ListNode* addTwoNumbers(ListNode* t1, ListNode* t2) {
        int carry = 0;
        ListNode* head=NULL,*end = NULL ;

        while(t1 and t2){
            int sum = t1->val+t2->val+carry;
            carry = sum/10;
            int add = sum%10;
            ListNode* temp = create(add);

            if(head==NULL){
                head = temp;
                end = temp;
            }
            else{
                end -> next = temp;
                end = temp;
            }
            t1=t1->next;
            t2=t2->next;
        }

        while(t1!=NULL){
            int sum = t1->val+carry;
            carry = sum/10;
            int add = sum%10;
            ListNode* temp = create(add);

            if(head==NULL){
                head = temp;
                end = temp;
            }
            else{
                end -> next = temp;
                end = temp;
            }
            t1=t1->next;

        }
          while(t2!=NULL){
            int sum = t2->val+carry;
            carry = sum/10;
            int add = sum%10;
              ListNode* temp = create(add);

            if(head==NULL){
                head = temp;
                end = temp;
            }
            else{
                end -> next = temp;
                end = temp;
            }
            t2=t2->next;

        }
        if(carry!=0){
             ListNode* temp = create(carry);
             end -> next = temp;
             end = temp;
        }

        return head;
    }

    ListNode* create(int add){
        ListNode* temp = new ListNode;
        temp ->val = add;
        temp ->next = NULL;
        return temp;
    }
};
