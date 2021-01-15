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
