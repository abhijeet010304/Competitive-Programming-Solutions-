class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() ;
        int i = 0;
        int sum = nums[0];
        int currentSum = 0;
        while(i<n){
            currentSum +=nums[i];
            sum = max(sum, currentSum);
            if(currentSum<0)currentSum = 0;
            i++;
        }
        return sum;
    }
};