class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        if(n==1)return nums[0];

        vector<int> zr;
        zr.push_back(-1);
        for(int i=0;i<n;i++) {
            if(nums[i]==0){
                zr.push_back(i);
            }
        }
        zr.push_back(n);

        vector<int> prefprod(n+1),sufprod(n+1);
        int sz = zr.size();
        for(int j=0;j<sz-1;j++){
            int start = zr[j];
            int end = zr[j+1];


                for(int i=start+1;i<end;i++){
                    if(i==start+1){
                         prefprod[start+1]=nums[start+1];
                    }
                    else{
                        prefprod[i] = prefprod[i-1]*nums[i];
                    }
                }
               for(int i=end-1;i>=start+1;i--){
                 if(i==end-1){
                     sufprod[end-1]=nums[end-1];
                    }
                 else{
                    sufprod[i] = sufprod[i+1]*nums[i];
                }

                }
        }


        int check =0;
        int ans= -1e9;
        for(int j=0;j<sz-1;j++){
            int start = zr[j];
            int end = zr[j+1];
            check =0;
            for(int i=start+1;i<end;i++){
                if(nums[i]<0){
                    check++;
                }
                if(check%2!=0){
                    if(i==start+1){
                        ans = max({ans,sufprod[i+1]});
                    }
                    else if(i==end-1){
                        ans = max({ans,prefprod[i-1]});
                    }
                    else
                        ans = max({ans,prefprod[i-1],sufprod[i+1]});
                }
                else{
                    ans = max({ans,prefprod[i],sufprod[i]});
                }

            }
        }

        return ans;

    }
};


// Only those who overflow with love will build the happy and enlightened world of the future.
