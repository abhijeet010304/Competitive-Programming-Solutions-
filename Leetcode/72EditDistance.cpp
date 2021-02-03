class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        int ans = 0;
        dp.resize(word1.length()+1,vector<int>(word2.length()+1,-1));
        ans = helper(word1,word2,word1.length(),word2.length());
        return ans ;
    }
    int helper(string &word1, string &word2,int n ,int m){
        if(dp[n][m]!=-1)return dp[n][m];
        if(n==0){dp[n][m] = m;
                 return m;
                }
        if(m==0){dp[n][m] = n;
                 return n;
                }

        if(word1[n-1]==word2[m-1]){
            dp[n][m] = helper(word1,word2,n-1,m-1);
            return dp[n][m];
        }
        else{
            dp[n][m] = min({1+helper(word1,word2,n-1,m),1+helper(word1,word2,n,m-1),helper(word1,word2,n-1,m-1)+1});
            return dp[n][m] ;
        }
    }
};
