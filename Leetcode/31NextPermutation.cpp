/*
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int count =0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])count++;

        }
        int n = nums.size();
        if(count==n-1){
            reverse(nums.begin(),nums.end());

        }
        else
        next_permutation(nums.begin(),nums.end());

    }
};

*/


/*

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int> nse = next_small(nums);
        int n = nums.size(),i;

        int count = 0;
        for(int i=0;i<n;i++){
            if(nse[i]!=-1){
                nse[i] = n-1-nse[i];
            }
            else count++;
        }
        if(count==n){
            reverse(nums.begin(),nums.end());
            return;
        }

        int mx = -1,loc;
        for(int i=n-1;i>=0;i--){
            if(nse[i]!=-1){
                if(nse[i]>mx  ){

                mx = max(mx,nse[i]);
                loc = i;

                }
            }
        }

        swap(nums[mx],nums[loc]);
        sort(nums.begin()+mx+1,nums.end());

    }
    vector<int> next_small(vector<int>arr){
    reverse(arr.begin(),arr.end());
    int n = arr.size();
    stack<int> s;
    vector<int> v;
    v.push_back(-1);
    s.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!s.empty() and arr[s.top()]>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            v.push_back(-1);
        }
        else v.push_back(s.top());
        s.push(i);
    }


    return v;

    }
};

*/
