auto speedup= [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return (0);
}();
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> temp;
        for(int i=1;i<=nums.size();i++)   {
            if(mp[target-nums[i-1]]){
                temp.push_back(i-1);
                temp.push_back(mp[target-nums[i-1]]-1);
                return temp;
            }
            else{
                mp[nums[i-1]]=i;

            }
        }
        return temp;


    }
};
