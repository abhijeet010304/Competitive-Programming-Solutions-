class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>>  ret;
        int n = nums.size();
        set<vector<int>> st;
        int i=0;
        while(i<n){
            int p1 = i+1,p2 = n-1;
            int target = -1*nums[i];

            while(p1<p2){
                if(nums[p1]+nums[p2]>target){
                    p2--;
                }
                else if(nums[p1]+nums[p2]<target){
                    p1++;
                }
                else if(nums[p1]+nums[p2]==target){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[p1]);
                    temp.push_back(nums[p2]);
                    st.insert(temp);
                    temp.clear();
                    p1++;
                    p2--;
                }
            }
            skip(i,nums);




        }

           for(auto x: st){
                ret.push_back(x);
            }
        return ret;
    }

    void skip(int &i, vector<int> nums){
        int val = nums[i];
        int n = nums.size();
        while(i<n and nums[i]==val ) {
            i++;
        }
    }
};
