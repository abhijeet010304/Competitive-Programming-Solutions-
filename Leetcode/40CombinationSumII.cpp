class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result ;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        int sum =0;
        for(auto x: candidates)sum+=x;
        if(sum<target)return result;
        backtrack(candidates,result,temp,0,target);

        return result;
    }
    void backtrack(vector<int> candidates,vector<vector<int>>&result,vector<int>temp,int start,int target){
        if(target==0){
            result.push_back(temp);
            return ;
        }
        if(target<0)return ;

        for(int i=start;i<candidates.size();i++){
                if(i>start and candidates[i]==candidates[i-1])continue;
                if(candidates[i]<=target){
                    temp.push_back(candidates[i]);
                    backtrack(candidates,result,temp,i+1,target-candidates[i]);
                    temp.pop_back();
                }
                else break;



        }
    }
};
