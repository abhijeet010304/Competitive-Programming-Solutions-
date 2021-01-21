class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()==0)return ans;
        vector<int> temp;
        backtrack(nums,ans,0,temp);
        return ans ;

    }
    void backtrack(vector<int> nums,vector<vector<int>> &ans,int start,vector<int> temp){
        ans.push_back(temp);
        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(nums,ans,i+1,temp);
            temp.pop_back();
        }
    }
};
