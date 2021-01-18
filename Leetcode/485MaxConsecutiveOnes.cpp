class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int p1 = 0,p2 = 0;
        int n = nums.size();
        int ans = 0;
        while(p2<n){
            if(nums[p2]==1){

                while(p2<n and nums[p2]==1)p2++;
                ans = max(ans,p2-p1);

            }
            else{
                p2++;
                p1 = p2;
            }
        }
        ans = max(ans,p2-p1);
        return ans;

    }
};
