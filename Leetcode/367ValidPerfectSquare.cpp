class Solution {
public:
    bool isPerfectSquare(int num) {
        for(int i=0;i<46341;i++){
            if(i*i*1==num){
                return true;
            }
            if(1L*i*i>num)break;
        }
        return false;
    }
};
