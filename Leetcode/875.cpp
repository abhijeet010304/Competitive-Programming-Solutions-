auto speedup = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
#pragma GCC optimize("Ofast")

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {

        int left = 1 , right = 1e9;
        while(left < right){
            int mid = left + (right - left)/2;
            if(condition(piles,mid,H)){
                right = mid ;
            }
            else{
                left = mid +1;
            }

        }


        return left ;

    }
    bool condition (vector<int> &piles,int mid,int H){

    int count = 0,speed = mid,total = 0,time = 0;
    for(int i = 0;i<piles.size();i++){
        total = piles[i];
        time += (speed + total -1)/speed;
        if(time > H) return false;

    }
     return true ;

 }
};
