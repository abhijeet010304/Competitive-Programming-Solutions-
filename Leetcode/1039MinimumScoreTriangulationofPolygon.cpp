class Solution {
public:
    vector<vector<int>> dp;
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        int ans = helper(A,0,n-1);
        return ans;
    }
    int helper(vector<int> &A,int start,int end){
        if(dp[start][end]!=-1)return dp[start][end];
        if(end<start+2){ // failure condition here
            dp[start][end] = 0;
            return 0;
        }
        int temp=0 ;
        int ans = 1e9;

        for(int i=start+1;i<end;i++){

            int part1 = helper(A,start,i);
            int part2 = helper(A,i,end);
            temp =A[i]*A[start]*A[end] + part1+part2;

            ans = min(temp,ans);
            dp[start][end];
        }


        dp[start][end] = ans;
        return ans;
    }
};
