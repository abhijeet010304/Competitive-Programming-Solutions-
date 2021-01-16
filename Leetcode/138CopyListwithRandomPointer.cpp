/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ret = NULL,*temp = head,*prev = NULL;
        while(temp){
            if(!ret){
                Node* newn = new Node(temp->val);
                ret = newn;
                prev = ret;
            }
            else{
                Node* newn = new Node(temp->val);
                prev->next = newn;
                prev = newn;
            }
            temp = temp ->next;
        }
        temp = head;
        prev = ret;
        while(temp){
            Node* check = temp ->random;

            Node* start = ret,*temphead = head;
            int val = 0;
            while(check!=temphead){
                temphead = temphead->next;
                val++;


            }
            while(val--){
                start = start->next;
            }
            prev->random = start;
            prev = prev->next;
            temp = temp->next;
        }
        return ret;

    }
};
