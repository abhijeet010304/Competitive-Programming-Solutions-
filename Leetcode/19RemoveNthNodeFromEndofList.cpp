/*
2 - pass solution 
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head,*prev = head;

        while(temp){
            count++;
            temp=temp->next;
        }
        count = count - n;
        temp = head;
        if(count==0){
            head =head->next;
        }

        while(count--){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        return head;


    }
};
