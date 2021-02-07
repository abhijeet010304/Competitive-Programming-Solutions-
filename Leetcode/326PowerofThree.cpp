class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return false;

        while(n>=3){
            if(n%3!=0)return false;
            else n/=3;
        }
        if(n==1)return true;
        if(n==2 or n==0)return false;
        return true;
    }
};
