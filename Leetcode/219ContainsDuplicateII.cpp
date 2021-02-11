class Solution {
public:
    bool sortfun(const pair<int,int> &a, const pair<int,int>&b){
        if(a.first<b.first)return true;
        else if(a.first==b.first and a.second<b.second)return true;
        else return false;

    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});


        }
        sort(v.begin(),v.end());
//         for(auto x: v){
//             cout<<x.first<<" "<<x.second<<"\n";        }

        int start= 0,end =0,prev =0;
        for(int i=0;i<n-1;i++){
            if(v[i].first==v[i+1].first){
                if(abs(v[i].second-v[i+1].second)<=k)return true;
            }
        }
        return false;
    }
};
