class Solution {
public:
    int mySqrt(int x) {
        int left{1},right = 100000;
        while(left < right ){
            long long int  mid = left + (right - left )/2;
            if(mid*mid>x){
                right = mid;
            }
            else left = mid+1;
        }
        return left -1;
    }
};
