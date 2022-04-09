class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i<n ;i++){
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for(auto x: mp){
            pq.push({x.second, x.first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};