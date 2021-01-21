class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans ;
        if(nums.size()==0)return ans;
        vector<int> temp;
        backtrack(nums,ans,0,temp);
        set<vector<int>> st;
        for(auto x:ans){
            sort(x.begin(),x.end());
            st.insert(x);
        }
        ans.clear();
        for(auto x: st){

            ans.push_back(x);
        }
        return ans;
    }
    void backtrack(vector<int>nums,vector<vector<int>>&ans,int start,vector<int> temp ){

        ans.push_back(temp);
        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(nums,ans,i+1,temp);
            temp.pop_back();
        }

    }
};
