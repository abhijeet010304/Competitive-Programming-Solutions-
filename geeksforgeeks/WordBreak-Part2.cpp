#include<bits/stdc++.h>
using namespace std;
void backtrack(set<string> st,string s,vector<vector<string>>& result, unordered_map<string, bool> &check, vector<string> &temp   ){
    if(s.length()==0){
        result.push_back(temp);
        return ;
    }
    //in geeks for geeks we want all solutions so commenting the already checked string
    // in leetcode it gives TLE 
    // if(check[s]==true)return ;
    // check[s] = true;

    for(auto x: st){
        if(s.find(x)==0){
            temp.push_back(x);
            backtrack(st,s.substr(x.length()),result, check, temp);
            temp.pop_back();
        }
    }
}
vector<vector<string>> getans(set<string> st,string s){
    vector<vector<string>> result;
    unordered_map<string, bool> check;
    vector<string> temp ;
    backtrack(st,s,result,check, temp);
    return result;
}


int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    set<string> st;
	    string s;
	    for(int i=0;i<n;i++){

	        cin>>s;
	        st.insert(s);
	    }
	    cin>>s;
	    vector<vector<string>> ans = getans(st,s);
	    if(ans.size()){
	        for(auto x: ans ){
	            sort(x.begin(),x.end());
	        }
	        sort(ans.begin(),ans.end());
	        for(auto x: ans){
	            cout<<"(";
	            int i=0;
	            for(i=0;i<x.size()-1;i++){
	                cout<<x[i]<<" ";
	            }
	            if(x.size())
	                cout<<x[i];
	            cout<<")";
	        }
	        cout<<"\n";
	    }
	    else cout<<"Empty\n";


	}
	return 0;
}
