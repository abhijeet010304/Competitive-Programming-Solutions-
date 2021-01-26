class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int start = 0,end = k-1;
        unordered_map<int,int>check;
        for(int i=start;i<=end;i++){
            pq.push(nums[i]);
            check[nums[i]]++;
        }
        vector<int> ret;
        int val ,n = nums.size();
        while(end<n-1){
            while(check[pq.top()]<=0)pq.pop();
            ret.push_back(pq.top());
            end++;

            pq.push(nums[end]);
            check[nums[end]]++;
            check[nums[start]]--;
            start++;
        }
        while(check[pq.top()]<=0)pq.pop();
        ret.push_back(pq.top());


        return ret;
    }
};

/*
approach 2
multiset
slower
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        int start = 0;
        vector<int> ret;
        int end = k-1;
        int n = nums.size();
        for(int i=start;i<=end;i++){
            st.insert(nums[i]);
        }

        while(end<n-1){

            ret.push_back(*st.rbegin());

            st.erase(st.find(nums[start]));
            end++;
            st.insert(nums[end]);
            start++;



        }
        ret.push_back(*st.rbegin());

        return ret;
    }
};
