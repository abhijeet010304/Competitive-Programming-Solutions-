/*
Without using STl inplace merge 

*/
class Solution {
public:
    int reversePairs(vector<int>& nums) {

     int ans = 0;
        int n = nums.size();
        merge_sort(nums,0,n,ans);
        return ans ;
    }
    void merge_sort(vector<int> &nums,int left ,int right,int &ans ){
        if(right -left<=1)return ;
        int mid = left+(right-left)/2;
        merge_sort(nums,left,mid,ans);
        merge_sort(nums,mid,right,ans);


        for(int i=left,j=mid;i<mid;i++){
            while(j<right and nums[i]>2L*nums[j])j++;
            ans += j-mid;
        }
        merge(nums,left,mid,right);
    }
    void merge(vector<int> &nums,int left,int mid,int right ){
        vector<int> temp;
        int i=left,j = mid;
        while(i<mid and j<right){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i++]);
            }
            else {
                temp.push_back(nums[j++]);
            }

        }
        while(i<mid)temp.push_back(nums[i++]);
        while(j<right)temp.push_back(nums[j++]);
        for(i=left;i<right;i++){
            nums[i]=temp[i-left];
        }
    }

};
