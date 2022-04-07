class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto x: stones){
            pq.push(x);
        }
        
        while(pq.size()>1){
            int l1 = pq.top();
            pq.pop();
            int l2 = pq.top();
            pq.pop();
            if(l1-l2>0)
                pq.push(l1-l2);
        }
        if(pq.size())return pq.top();
        else return 0;
    }
};