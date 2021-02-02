class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int i,j,n = nums.size();
        vector<int> lis(n,1);

        for(i=0;i<n;i++){
            for(j=0;j<i;j++){
                if(nums[j]<nums[i])
                    lis[i] = max(lis[i],lis[j]+1);
            }
        }

        return *max_element(lis.begin(),lis.end());

    }

};
