class Solution {
public:
    double myPow(double x, int n) {
        double ans ;
        ans = powerCalc(x,abs(n));
        if(n<0)ans = 1/ans;
        return ans ;
        
    }
    
    double powerCalc(double x,int n){
        if(n==0)return 1;
        if(n==1)return x;
        double templeft = powerCalc(x,n/2) ;    
        templeft = templeft*templeft;
        if(n%2==0){
            return templeft;
        }
        else return x*templeft;

        
    }
};
