class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        bool first = false;
        int prev;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                if(first==false){
                    prev = i;
                    first = true;
                }
                else {
                    if(i-prev-1<k)return false;
                    else{
                        prev = i;
                    }
                }
            }
        }
        return true;
    }
};
