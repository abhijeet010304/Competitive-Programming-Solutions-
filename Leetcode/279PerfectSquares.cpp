class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);
        vector<vector<int>> dp(m,vector<int>(n+1,0));
        int i,j;
        for(i=0;i<m;i++){
            dp[i][0] = 0;
        }
        for(i=0;i<n+1;i++){
            dp[0][i] = i;
        }
        int cost = 2;
        for(i=1;i<m;i++){
            for(j=0;j<n+1;j++){
                if(j>=(i+1)*(i+1)){
                    dp[i][j] = min(dp[i-1][j],dp[i][j-(i+1)*(1+i)]+1);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[m-1][n];
    }
};
