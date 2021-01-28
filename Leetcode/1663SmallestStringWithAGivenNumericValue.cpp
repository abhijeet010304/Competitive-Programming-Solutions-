class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans (n,'a');
        int curr = n;
        for(int i=n-1;i>=0;i--){
            for(int j=25;j>=0;j--){
                char c = 'a'+j;
                int val = j+1;

                if(k-val>=curr-1){
                    k = k-val;
                    curr--;
                    ans[i]=c;
                    break;
                }
            }
            if(k<0)break;
        }
        return ans ;
    }
};
