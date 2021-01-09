/* Pure Brute force approach*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ret;
        if(n<4)return ret;
        unordered_map<int,pair<int,int>> mp;
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){

                    if(binary_search(nums.begin()+k+1,nums.end(),(target-(nums[i]+nums[j]+nums[k])))==true){
                        vector<int> temp;
                         temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(target-(nums[i]+nums[j]+nums[k]));
                        sort(temp.begin(),temp.end());
                    st.insert(temp);
                    }
                }


            }

        }

        for(auto x: st)ret.push_back(x);
        return ret;

    }
};
