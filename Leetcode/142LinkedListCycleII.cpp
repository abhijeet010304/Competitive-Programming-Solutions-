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
    ListNode *detectCycle(ListNode *head) {
        if(!head)return head;

        map<ListNode*,bool> mp;
        ListNode* temp = head;
        while(temp){
            if(mp[temp])return temp;
            else {
                mp[temp] = true;

            }
            temp = temp->next;

        }
        return temp;
    }
};

/*
TC: O(n^2)
SC: O(1)
*/

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
    ListNode *detectCycle(ListNode *head) {
        if(!head)return head;
        if(head->next==NULL)return NULL;
        else if(head->next==head)return head;

        ListNode*  temp = head,*slow =head,*fast = head;
        do{
            slow = slow->next;
            fast = fast->next;
            if(fast)fast = fast->next;
            else break;
        }while(slow and fast and slow!=fast);

        if(slow!=fast)return NULL;
        else {
            int ans = 1e9;
            ListNode *node =NULL;
            int count =0;
            while(temp!=slow){
                count ++;
                temp = temp->next;
            }
            if(count<ans){
                ans =count;
                node = slow;
            }

            slow = slow->next;
            while(slow!=fast){
                temp = head;
                count =0;
                while(temp!=slow){
                    count ++;
                    temp = temp->next;
                }
                if(count<ans){
                    ans =count;
                    node = slow;
                }
                slow = slow->next;
            }


            return node;
        }

    }
};

/*
O(N) and O(1)
tc and sc
*/
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
    ListNode *detectCycle(ListNode *head) {
        if(!head)return head;
        if(head->next==NULL)return NULL;
        else if(head->next==head)return head;

        ListNode*  temp = head,*slow =head,*fast = head;
        do{
            slow = slow->next;
            fast = fast->next;
            if(fast)fast = fast->next;
            else break;
        }while(slow and fast and slow!=fast);

        if(slow!=fast)return NULL;
        else {
            fast = head;
            //using fast to traverse from head to junction
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;;
        }

    }
};
