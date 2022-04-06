// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
       set<string>st = {B.begin(), B.end()};
       int ans = check(A, st);
       return ans;
       
    }
    int check(string a, set<string> &st){
        
        if(a.size()==0){
            return 1;
        }
        
        for(auto x: st){
            if(a.find(x)==0 and check(a.substr(x.size()), st)){
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends