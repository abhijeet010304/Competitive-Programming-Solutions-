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
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)return true;
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp ->next;
        }
        int a = len/2;
        if(len%2==0){
            stack<ListNode*> st;
            temp = head;
            while(a--){
                st.push(temp);
                temp = temp->next;
            }
            a = len/2;
            while(a--){
                ListNode* tp = st.top();
                if(tp->val!=temp->val)return false;
                temp = temp->next;
                st.pop();
            }
            return true;
        }
        else{
             stack<ListNode*> st;
            temp = head;
            while(a--){
                st.push(temp);
                temp = temp->next;
            }
            temp = temp->next;
            a = len/2;
            while(a--){
                ListNode* tp = st.top();
                if(tp->val!=temp->val)return false;
                temp = temp->next;
                st.pop();
            }
            return true;
        }
    }
};
