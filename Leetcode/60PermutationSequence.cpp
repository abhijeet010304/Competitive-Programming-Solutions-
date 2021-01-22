class Solution {
public:
    string getPermutation(int n, int k) {
        int select = k,fact = n,temp = n;
        vector<int> choice = {'1','2','3','4','5','6','7','8','9'};
        vector<int> fc = {1,1,2,6,24,120,720,5040,40320,362880};
        choice.resize(n);
        string ans ;
        while(temp--){
            int ind = (select-1)/fc[fact-1];
            ans+=choice[ind];
            select = select - ind*fc[fact-1];
            fact--;
            choice.erase(choice.begin()+ind);
        }
        return ans;
    }
};
