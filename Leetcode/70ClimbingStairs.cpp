class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        int ans  = check(n,dp);


        return ans ;
    }

    int check(int n, int *dp){
        if(dp[n]!=-1)return dp[n];
        if(n<1){
            dp[0]=0;
            return 0;
        }
        if(n==1 or n==2){
            dp[n] = n;
            return n;
        }


        dp[n] = (check(n-1,dp)+check(n-2,dp));
        return dp[n];
    }
};
