class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;

        dp[1] = 0;
        if(n==1)return dp[n];
        dp[2] = 2;
        if(n==2)return dp[n];
        dp[3] = 3;
        if(n==3)return dp[n];
        dp[4] = 4;
        if(n==4)return dp[n];
        dp[5] = 5;
        if(n==5)return dp[n];
        for(int i=6;i<=n;i++){
            dp[i] = 1e9;
        }
        set<int> st = factors(n);

        for(auto y:st){
            if(isprime(y))dp[y] = y;
            else{
                set<int> fact = factors(y);

                for(auto x: fact){
                    int val = dp[x]+y/x;
                    dp[y] = min(dp[y],val);
                }
            }
        }
        return dp[n];

    }

    set<int> factors(int n){
        set<int> st;

        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                st.insert(i);
                st.insert(n/i);
            }
        }
        return st;
    }
    bool isprime(int n){
        if(n==1)return false;
        if(n<=3)return true;
        if(n%2==0 or n%3==0)return false;
        for(int i=5;i*i<=n;i+=6){
            if(n%i==0 or n%(i+2)==0)return false;
        }
        return true;
    }
};
