class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        int i,j;

        sort(nums.begin(),nums.end());
        int n = nums.size();
        map<int,int> mp;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){

                int pr = nums[i]*nums[j];
                mp[pr]++;
            }
        }
        int ans = 0;
        for(auto x:mp){
            int val = x.second*(x.second-1);
            ans +=val*4;
        }
        return ans;
    }

};
