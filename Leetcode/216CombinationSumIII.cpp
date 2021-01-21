class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> choice(9);
        vector<vector<int>> result;
        vector<int> temp;
        for(int i=1;i<=9;i++){
            choice[i-1] = i;
        }
        backtrack(choice,result,temp,k,n,0);
        return result;
    }
    void backtrack(vector<int> choice, vector<vector<int>>&result, vector<int>temp, int k, int target,int start){
        if(temp.size()==k and target==0){
            result.push_back(temp);
            return ;
        }
        if(target<0)return ;
        for(int i=start;i<choice.size();i++){
            if(choice[i]<=target){
                temp.push_back(choice[i]);
                backtrack(choice,result,temp,k,target-choice[i],i+1);
                temp.pop_back();
            }
        }

    }
};
