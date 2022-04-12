class Solution {
public:
    double myPow(double x, int n) {
        double ans = powerIt(x,abs(n));
        if(n<0)ans = 1/ans;
        return ans ;
    }
    double powerIt(double x, int n){
        if(x==1)return 1;
        if(n==0)return 1;
        if(n==1)return x;
        double tempAns = powerIt(x,n/2);
        if(n%2!=0)return tempAns * tempAns * x;
        else return tempAns * tempAns;
    }
};