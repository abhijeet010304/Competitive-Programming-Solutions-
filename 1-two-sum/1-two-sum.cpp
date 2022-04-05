class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        map<int,int> mp;
        for( int i=1;i<=n;i++){
            if(mp[target-nums[i-1]]){
                ans.push_back(i-1);
                ans.push_back(mp[target-nums[i-1]]-1);
            }
            else mp[nums[i-1]] = i;
        }
        return ans;
    }
};