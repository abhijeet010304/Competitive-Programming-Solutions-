class Solution {
public:
    string reverseWords(string s) {
        int start = 0,end = 0;
        reverse(s.begin(),s.end());
        while(true){
            auto x = s.find("  ");
            if(x!=string::npos){

                s.erase(x,1);
            }
            else break;
        }

        if(s[0]==' ')s.erase(s.begin());
        if(s[s.length()-1]==' ')s.erase(s.begin()+s.length()-1);
        if(s.length()==0)return s;
        int n = s.length();
        while(end<n){
            start = end;
            while(end<n and s[end]!=' ')end++;

            reverse(s.begin()+start,s.begin()+end);

            end++;
        }

        return s;

    }
};
