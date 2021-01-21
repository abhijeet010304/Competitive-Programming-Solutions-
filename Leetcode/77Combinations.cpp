class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        if(n==1){
            temp.push_back(1);
            result.push_back(temp);
            return result;
        }
        backtrack(n,k,temp,result,1);
        return result;
    }
    void backtrack(int n,int k,vector<int>&temp,vector<vector<int>>&result,int start){
            if(temp.size()==k){
                result.push_back(temp);
                return ;
            }
            for(int i=start;i<=n;i++){
                temp.push_back(i);
                backtrack(n,k,temp,result,i+1);
                temp.pop_back();
            }
        }
};
