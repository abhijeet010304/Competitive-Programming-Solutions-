class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int count = 0;
        vector<string> words;
        string word = "";
        for(int i = 0;i<s.length();i++){
            if(s[i]==' '){
                words.push_back(word);
                word = "";
            }else{
                word+=s[i];
            }
        }
        words.push_back(word);
      
        if(words.size()!=pattern.length())return false;
        cout<< "here";
        map<string, bool> check;
        map<char, string> mp;
        for(int i = 0;i<pattern.length();i++){
            if(mp.find(pattern[i])!=mp.end()){
                if(mp[pattern[i]]!=words[i])return false;
            }
            else{
                if(!check[words[i]]){
                    mp[pattern[i]] = words[i];
                    check[words[i]] = true;
                }
                else return false;
                
                
            }
        }
        return true;
    }
};