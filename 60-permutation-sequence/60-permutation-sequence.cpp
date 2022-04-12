class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> choice(n), fact(n+1);
            fact[0] = 1;
        for(int i = 1;i<=n;i++){
            choice[i-1] = i;
            fact[i] = fact[i-1]*i;
        }
        string temp = "";
        permute(ans, temp, n, k, n, choice, fact);
        
        return ans;
    }
    
    void permute( string &ans , string temp, int n , int k, int sz, vector<int>&choice, vector<int> &fact){
        if(ans.length()>=sz){
            return;
        }
        
        int ind = k/fact[n-1];
        int mod = k%fact[n-1];
        if(mod==0){
            ind--;
            mod = fact[n-1];
        }
        temp+=choice[ind]+'0';
        ans = temp;
        k = mod;
        choice.erase(choice.begin()+ind);
        permute(ans, temp, n-1, k , sz, choice, fact);
    }
};