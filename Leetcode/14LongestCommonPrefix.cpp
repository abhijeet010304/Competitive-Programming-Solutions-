class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();
        if(!n)return "";
        int count = 0,check =-1;
        bool over = false;
        string ref = strs[0];
        int len = ref.size();
        for(int i=0;i<len;i++){
            count = 0;
            for(int j =1 ;j<n;j++){
                if(strs[j].length()>=i){
                    if(strs[j][i]==ref[i])count++;
                    else over = true;
                }
                else{
                    over = true;
                }
            }

            if(over)break;
            check = i;



        }
        return ref.substr(0,check+1);
    }
};
