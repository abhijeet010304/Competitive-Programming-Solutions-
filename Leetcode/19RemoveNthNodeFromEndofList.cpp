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


/*
One pass solution
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode *prev = head,*fast = head,*slow = head;
        int move = n-1;
        while(move--){
            fast = fast->next;
        }
        while(fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if(slow==head)head = head->next;

        prev ->next = slow->next;
        return head;



    }
};
