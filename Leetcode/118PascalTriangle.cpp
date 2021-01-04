class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans ;
        if(numRows==0)return ans ;
        if(numRows==1){
            vector<int> temp;
            temp.push_back(1);
            ans.push_back(temp);
            return ans;

        }

        vector<int> temp;
            temp.push_back(1);
            ans.push_back(temp);
            temp.push_back(1);
            ans.push_back(temp);
        for(int i=1;i<=numRows-2;i++){
            int sz = temp.size();
            vector<int> newt;
            newt.push_back(1);
            sz--;
            int p1=0,p2=1;
            while(sz--){
                newt.push_back(temp[p1++]+temp[p2++]);
            }
            newt.push_back(1);
            ans.push_back(newt);
            temp.clear();
            temp = newt;
            newt.clear();
        }
        return ans ;
    }
};
