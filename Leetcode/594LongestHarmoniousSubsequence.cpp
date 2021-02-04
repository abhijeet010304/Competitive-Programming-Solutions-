class Solution {
public:
    int findLHS(vector<int>& arr) {
        int i,j,n = arr.size();
        if(n<=1)return 0;

        unordered_map<int,int> mp;


        for(i=0;i<n;i++){
            mp[arr[i]]++;

        }

        int ans = 0;
        for(auto x:mp){

            if(mp.find(x.first+1)!=mp.end())
                ans  = max({ans,mp[x.first+1]+x.second});
            if(mp.find(x.first-1)!=mp.end())
                ans  = max({ans,mp[x.first-1]+x.second});


        }
        return ans;


    }
};
