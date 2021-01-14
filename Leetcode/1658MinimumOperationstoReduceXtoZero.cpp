class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(),i;
        vector<int> pre(n),suf(n);
        for(i=0;i<n;i++){
            if(i==0){
                pre[i]=nums[i];
                suf[i] = nums[n-1-i];
            }
            else {

                pre[i]=pre[i-1]+nums[i];
                suf[i] =  suf[i-1]+nums[n-1-i];
            }

        }


        int ans = 1e9;
        for(i=0;i<n;i++){
            if(pre[i]>x)break;
            else if(pre[i]==x){
                ans = min(ans,i+1);
            }
            else{
                int target = x-pre[i];
                int val = lower_bound(suf.begin(),suf.end()-i-1,target)-suf.begin();

                if(target==suf[val]){
                    ans = min(ans,i+val+2);

                }

            }
        }

        for(i=0;i<n;i++){
            if(suf[i]>x)break;
            else if(suf[i]==x){
                ans = min(ans,1+i);
            }
            else{
                int target = x-suf[i];
                int val = lower_bound(pre.begin(),pre.end()-i-1,target)-pre.begin();
                if(target==pre[val]){
                    ans = min(ans,i+val+2);


                }
            }
        }

        if(ans<=n)return ans;
        else return -1;
    }
};
