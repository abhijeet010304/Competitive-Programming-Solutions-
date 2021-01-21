class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,result,temp,0,target);
        return result;
    }
    void backtrack(vector<int>candidates,vector<vector<int>> &result,vector<int>&temp,int start,int target){
        if(target<0)return;
        if(target==0){
            result.push_back(temp);
            return ;
        }

        for(int i=start;i<candidates.size();i++){
                if(candidates[start]<=target){
                    temp.push_back(candidates[i]);
                    backtrack(candidates,result,temp,i,target-candidates[i]);
                    temp.pop_back();
                }
            else{
                break;
            }

        }
    }
};
