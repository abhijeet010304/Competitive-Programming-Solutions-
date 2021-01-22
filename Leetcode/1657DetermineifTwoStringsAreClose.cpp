/*
can be optimized a lot 
*/
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> s1,s2;
        unordered_map<char,int> mp;
        set<char> st1,st2;
        for(auto x:word1)st1.insert(x);
        for(auto x:word2)st2.insert(x);
        if(st1!=st2)return false;
        for(auto x:word1)mp[x]++;
        for(auto x:mp)s1.push_back(x.second);
        mp.clear();
        for(auto x:word2)mp[x]++;
        for(auto x:mp)s2.push_back(x.second);
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
};
