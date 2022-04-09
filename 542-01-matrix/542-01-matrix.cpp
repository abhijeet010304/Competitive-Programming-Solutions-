class Solution {
public:
    vector<int> r = {-1,0,1,0};
    vector<int> c = {0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 1e6));
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        for(int i =0 ;i<row;i++){
            for(int j = 0;j<col;j++){
                if(mat[i][j]==0){
                    dp[i][j] = 0;
                    continue;
                }
                int a = 1e6,b = 1e6;
                if(valid(i-1, j, row, col)){
                    a = dp[i-1][j];
                }
                if(valid(i, j-1, row, col)){
                    b = dp[i][j-1];
                }
                
                dp[i][j] =1+ min(a,b);
                
            }
        }
        
        
        for(int i =row-1 ;i>=0;i--){
            for(int j = col-1;j>=0;j--){
                if(mat[i][j]==0){
                    dp[i][j] = 0;
                    continue;
                }
                int a = 1e6,b = 1e6;
                if(valid(i+1, j, row, col)){
                    a = dp[i+1][j];
                }
                if(valid(i, j+1, row, col)){
                    b = dp[i][j+1];
                }
                
                dp[i][j] = min({a+1,b+1,dp[i][j]});
                
            }
        }
        
        
        return dp;
    }
    bool valid(int i, int j, int r, int c){
        return (i>=0 and i<r and j>=0 and j<c);
    }
  
};