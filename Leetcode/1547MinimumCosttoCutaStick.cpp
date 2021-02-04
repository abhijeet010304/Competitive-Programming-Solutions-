class Solution {
public:
    vector<vector<int>> dp;
    int minCost(int n, vector<int>& cuts) {
        dp.resize(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        sort(cuts.begin(),cuts.end());
        int ans = helper(0,n,cuts,0,cuts.size()-1);
        return ans ;

    }
    int helper(int start,int end, vector<int>& cuts,int indS,int indE){
        if(indS>indE)return 0;
        if(dp[indS][indE]!=-1)return dp[indS][indE];

        if(end-start==1)return 0;

        int ans=1e9 ,temp;
        for(int i=indS;i<=indE;i++){
            int left =  helper(start,cuts[i],cuts,indS,i-1);
            int right = helper(cuts[i],end,cuts,i+1,indE);

            temp = left +end-start + right;
            ans = min(ans,temp);

        }
        dp[indS][indE] = ans;
        return ans;
    }
};
