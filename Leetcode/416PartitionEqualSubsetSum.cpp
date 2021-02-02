class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int i,n = nums.size(),sum=0;
        for( i=0;i<n;i++){

            sum+=nums[i];
        }

        int w = sum/2;
        if(sum%2!=0) return false;

        vector<vector<bool>> dp(n+1,vector<bool>(sum/2+1,false));
        for( i=0;i<=w;i++){

            dp[0][i] = false;
        }
        for( i=0;i<=n;i++){

            dp[i][0] = true;
        }
        for(i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                if(nums[i-1]<=j){
                    if(dp[i-1][j-nums[i-1]] or dp[i-1][j])dp[i][j] = true;
                }
                else{
                    if(dp[i-1][j])dp[i][j] = true;
                }
            }
        }
        return dp[n][w];
    }
};
