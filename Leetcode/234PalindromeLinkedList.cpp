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

/*
O(N) - TC
O(1) - SC
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
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next ) return true;
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp ->next;
        }
        int a = len/2;
        if(len%2==0){
            temp = head;
            ListNode* prev = NULL;
            while(a--){
                prev = temp;
                temp = temp ->next;
            }
            prev ->next = reversell(temp);
            prev = prev ->next;
            temp = head;
            a = len/2;

            while(a--){
                if(temp->val!=prev->val)return false;
                temp = temp->next;
                prev = prev->next;
            }
            return true;

        }
        else{
            temp = head;
            ListNode* prev = NULL;
            a++;
            while(a--){
                prev = temp;
                temp = temp ->next;
            }
            prev ->next = reversell(temp);
            prev = prev ->next;
            temp = head;
            a = len/2;

            while(a--){
                if(temp->val!=prev->val)return false;
                temp = temp->next;
                prev = prev->next;
            }
            return true;
        }

    }

    ListNode* reversell(ListNode* head){
        if(!head or !head->next) return head;
        ListNode *prev = NULL, *curr = head, *Next= curr->next;
        while(Next){
            curr->next = prev;
            prev = curr;
            curr = Next;
            Next = Next->next;
        }
        curr->next = prev;
        return curr;

    }
};
