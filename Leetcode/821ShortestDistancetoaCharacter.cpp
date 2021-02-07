class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n  = s.length(),i,inf = 1e9;
        vector<int> front(n),back(n);
        for(i=0;i<n;i++){
            front[i] = inf;
            back[i] = inf;
        }
        for(i=0;i<n;i++){
            if(s[i]==c)front[i] = 0;
            else if(i-1>=0 and front [i-1]!=inf){
                front[i] = front[i-1]+1;
            }
        }
        for(i=n-1;i>=0;i--){
            if(s[i]==c)back[i]= 0;
            else if(i+1<n and back[i+1]!=inf){
                back[i] = back[i+1]+1;
            }

        }
        for(auto c: front)cout<<c<<" ";
        cout<<"\n";
        for(auto c: back)cout<<c<<" ";
        cout<<"\n";
        vector<int> ans(n);
        for(i=0;i<n;i++){
            ans[i] = min(front[i],back[i]);
        }
        return ans;


    }
};
