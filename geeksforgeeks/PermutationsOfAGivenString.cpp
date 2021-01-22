#include<bits/stdc++.h>
using namespace std;
void backtrack(string s , vector<string >&ans, string &temp ,char ch){
    if(temp.length()==s.length()){
        ans.push_back(temp);
        return;
    }

    if(temp.length()>s.length())return ;

    for(int i=0;i<s.length();i++){
        if(temp.find(s[i])!=string::npos)continue;
        else{
            temp+=s[i];
            backtrack(s,ans,temp,s[i]);
            temp.erase(temp.length()-1,1);
        }
    }
}
vector<string> getans(string s){
    string temp = "";
    vector<string> ans;
    if(s.length()<=1){
        ans.push_back(s);
        return ans ;
    }
    backtrack(s,ans,temp,'$');
    return ans ;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    vector<string> ans;
	    ans = getans(s);
	    sort(ans.begin(),ans.end());
	    for(auto x: ans)cout<<x<<" ";
	    cout<<"\n";
	}
	return 0;

}
