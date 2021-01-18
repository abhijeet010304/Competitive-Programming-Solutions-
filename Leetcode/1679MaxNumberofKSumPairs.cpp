class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int p1 = 0,p2 = n-1,count=0;

        while(p1<p2){
            if(nums[p1]+nums[p2]==k){
                count++;
                p1++;
                p2--;
            }
            else if(nums[p1]+nums[p2]>k){
                p2--;
            }
            else{
                p1++;
            }

        }
        return count ;
    }
};
