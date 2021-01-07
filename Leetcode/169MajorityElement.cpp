class Solution {
public:
    //o(1) space complexity , o(N) Time
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans  =nums[0];
        int count =0;
        for(int i=0;i<n;i++){
            if(count==0){
                ans = nums[i];
                count++;
            }
            else if(nums[i]==ans){
                count++;

            }
            else{
                count-=1;
            }
        }
        return ans;
    }

};
