class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = *max_element(days.begin(),days.end())+1;
        int m =3;
        vector<vector<int>> dp(m,vector<int>(n,0));
        int i,j;
        for(int i=0;i<3;i++){
            dp[i][0] = 0;
        }
        int minn = 0;
        for(j=1;j<n;j++){
            if(binary_search(days.begin(),days.end(),j)){
                minn = min({dp[0][max(j-1,0)]+costs[0],dp[1][max(j-7,0)]+costs[1],dp[2][max(j-30,0)]+costs[2]});
                for(int k=0;k<3;k++){
                    dp[k][j] = minn;
                }
            }
            else {
                for(int k=0;k<3;k++){
                    dp[k][j] = minn;
                }
            }
        }
        return dp[0][n-1];
    }
};
