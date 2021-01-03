class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z =0,o =0,t =0,i,n = nums.size();
        for(i=0;i<n;i++){
            if(nums[i]==0)z++;
            if(nums[i]==1)o++;
            if(nums[i]==2)t++;
        }
        for(i=0;i<n;i++){
            if(z)nums[i]=0,z--;
            else if(o)nums[i]=1,o--;
            else if(t)nums[i]=2,t--;
        }
    }
};
