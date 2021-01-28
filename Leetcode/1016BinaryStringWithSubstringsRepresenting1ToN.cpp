class Solution {
public:
    bool queryString(string S, int N) {
        for(int i=1;i<=N;i++){
            if(!check(i,S))return false;
        }
        return true;
    }
    bool check(int i,string &S){
        string s = bitset<32>(i).to_string();
        while(true){
            if(s.find('0')==0){
                s.erase(0,1);
            }
            else break;
        }
        if(S.find(s)!=string::npos)return true;
        else return false;
    }
};
