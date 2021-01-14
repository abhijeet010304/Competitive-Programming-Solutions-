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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        if(!head->next)return head;
        ListNode* cur = head, *pre = NULL;
        int n = k;
        int  count = 0;
        pre = head;
        while(pre){
            pre = pre->next;
            count++;
        }
        n = n%count;
        while(n--){

            cur = cur->next;
        }
        pre = head;
        while(cur->next){
            pre = pre->next;
            cur=cur->next;
        }

        cur->next =head;
        head = pre->next ;
        pre->next = NULL;
        return head;


    }
};
