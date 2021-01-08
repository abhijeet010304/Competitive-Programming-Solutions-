//moore voting algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int me1,me2,count1 =0,count2 = 0;

        for(int i=0;i<nums.size();i++){

            if(nums[i]==me1)count1++;
            else if(nums[i]==me2)count2++;
            else if(count1==0){
                me1 = nums[i];
                count1 = 1;
            }
            else if(count2==0){
                me2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }

        }
        count1=0;
        count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==me1)count1++;
            else if(nums[i]==me2)count2++;
        }
        vector<int> ans;

        if(count1>nums.size()/3)ans.push_back(me1);
        if(count2>nums.size()/3)ans.push_back(me2);
        return ans ;
    }
};
