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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode *head=NULL;
        if(n==0)return head;
        if(n==1){
            head = lists[0];
            return head;
        }

        head = mergelist(0,1,n,lists);
        return head;
    }

    ListNode* mergelist(int ind1,int ind2,int &n,vector<ListNode*> &lists){
        cout<<lists.size()<<"\n";
        if(ind2>=n)return NULL;
        if(ind2==n-1){
            n--;
            ListNode* temp = merger(lists[ind1],lists[ind2]);
            return temp;
        }
        else return merger(lists[ind1],mergelist(ind2,ind2+1,n,lists));

    }
    ListNode* merger(ListNode* head1,ListNode* head2){
        ListNode* temphead = NULL;
        if(head1==NULL and head2==NULL)return head1;
        if(head2==NULL)return head1;
        if(head1==NULL)return head2;

        ListNode* p1=head1,*p2=head2,*end;
        while(p1 and p2){
            if(temphead==NULL){
                if(p1->val<=p2->val){
                    temphead = p1;
                    end = p1;
                    p1 = p1->next;
                }
                else{
                    temphead = p2;
                    end = p2;
                    p2 = p2->next;
                }

            }
            else{
                 if(p1->val<=p2->val){

                    end->next = p1;
                    end  = p1;
                    p1 = p1->next;
                }
                else{
                    end->next = p2;
                    end = p2;
                    p2 = p2->next;
                }

            }

        }
        if(p1){
            while(p1){
                end ->next = p1;
                end = p1;
                p1 = p1->next;
            }
            end ->next = NULL;

        }
        if(p2){
            while(p2){
                end ->next = p2;
                end = p2;
                p2 = p2->next;
            }
            end ->next = NULL;

        }
        return temphead;
    }
};
