class Solution {
public:
    string longestPalindrome(string s) {
        int i,n = s.length();
        string ans ;
        for(i=0;i<n;i++){
            string temp = check(i,n,s);
            if(temp.length()>ans.length()){
                ans = temp;
            }
        }
        return ans ;
    }

    string check(int i,int n,string s){
        pair<int,int> p1 = checkeven(i,n,s);
        pair<int,int> p2 = checkodd(i,n,s);
        if(p1.second-p1.first > p2.second-p2.first){
            return s.substr(p1.first,p1.second+1-p1.first);
        }
        else return s.substr(p2.first,p2.second+1-p2.first);
    }
    pair<int,int> checkodd(int i,int n,string s){
        int start = i, end = i;
        while(start>=0 and end<n and s[start]==s[end]){
            start--;
            end++;
        }
        return {start+1,end-1};
    }
     pair<int,int> checkeven(int i,int n,string s){
        int start = i, end = i+1;
        while(start>=0 and end<n and s[start]==s[end]){
            start--;
            end++;
        }
        return {start+1,end-1};
    }
};
