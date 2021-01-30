class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(n,vector<int>((amount+1),0));
        int m = amount +1;
        int i,j;
        int inf = 1e9;
        for(i=0;i<m;i++){
            if(i%coins[0]==0)dp[0][i] = i/coins[0];
            else dp[0][i] = inf;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){

                if(coins[i]<=j){


                    dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i]]+1);

                }
                else dp[i][j] = dp[i-1][j];
            }
        }

        return (dp[n-1][m-1]<inf?dp[n-1][m-1]:-1);
    }
};
