
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {

        int left = *max_element(weights.begin(),weights.end()) ,right = 1000000000;
        while(left < right ){
            int mid = left + (right-left)/2;
            if(condition(mid,weights,D)){
                right = mid;

            }
            else{
                left = mid+1;
            }
        }
        return left;
    }

    bool condition(int mid,vector<int> weights,int D){
        int dayCount = 1,total = 0;
        for(int i = 0;i<weights.size();i++){
            total+=weights[i];
            if(total > mid){
                dayCount++;
                total = weights[i];
                if(dayCount>D)return false ;
            }


        }
        return true ;
    }

};
