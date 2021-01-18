class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n= nums.size();
        if(n<2)return n;
        int p1 = 0,p2 =1;
        while(p2<n){
            int val = nums[p1];

            while(p2<n and nums[p2]==val){
                nums.erase(nums.begin()+p2);
                n = nums.size();
            }
            p1 = p2;
            p2++;
            n = nums.size();

        }


        return n;
    }
};
