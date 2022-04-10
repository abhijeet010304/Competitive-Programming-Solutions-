class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> ans;
        for(auto x: ops){
            if(x=="C"){
                ans.pop_back();
            }
            else if(x=="D"){
                int sz = ans.size();
                ans.push_back(ans[sz-1]*2);
            }
            else if(x=="+"){
                int sz = ans.size();
                ans.push_back(ans[sz-1]+ans[sz-2]);
            }
            else{
                int val = stoi(x);
                ans.push_back(val);
            }
        }
        
        int sum = 0;
        for(auto x: ans){
            sum+=x;
        }
        return sum;
    }
};