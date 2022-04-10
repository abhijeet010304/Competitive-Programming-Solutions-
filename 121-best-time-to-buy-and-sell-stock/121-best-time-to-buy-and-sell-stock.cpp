class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> m(n);
        for(int i = n-1;i>=0;i--){
            if(i==n-1)m[i] = prices[i];
            else m[i] = max(prices[i], m[i+1]);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans = max(ans, m[i]-prices[i]);
        }
        return ans;
    }
};