/* Pure Brute force approach*/
/*
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ret;
        if(n<4)return ret;
        unordered_map<int,pair<int,int>> mp;
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){

                    if(binary_search(nums.begin()+k+1,nums.end(),(target-(nums[i]+nums[j]+nums[k])))==true){
                        vector<int> temp;
                         temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(target-(nums[i]+nums[j]+nums[k]));
                        sort(temp.begin(),temp.end());
                    st.insert(temp);
                    }
                }


            }

        }

        for(auto x: st)ret.push_back(x);
        return ret;

    }


};
*/

/*
optimized with 2pointer time = O(n^3)


*/
class Solution {
public:
    vector<int> global;
    int n;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i=0, j;
        n = nums.size();
        sort(nums.begin(),nums.end());
        global = nums;
        vector<vector<int>> ret;

        while(i<n){
            j = i+1;
            while(j<n){
                int l = j+1,r = n-1;
                while(l<r){
                    int current = nums[i]+nums[j];
                    int need = target - current;
                    vector<int>ans = search(l,r,need);
                    if(ans.size()==2){
                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ret.push_back(ans);
                    }
                    skip(l,r);
                }
                skip(j);
            }

            skip(i);

        }
        return ret;
    }

    vector<int> search(int &l,int &r, int target){
        vector<int> ans;
        if(l>=r) return ans;
        while(l<r){
                if(global[l]+global[r]==target){
                ans.push_back(global[l]);
                ans.push_back(global[r]);
                return ans;
            }
            else{
                if(global[l]+global[r]>(target))r--;
                else l++;

                if(target==1)cout<<l<<" ";
            }
        }
        return ans ;
    }
    void skip(int &l, int &r){
        if(l>=r) return ;
        int prev = global[l];

        if(l<n-1)l++;
        while(l<n and global[l]==prev)l++;
        prev = global[r];
        if(r>=l+1)r--;
        while(r>l and global[r]==prev )r--;
    }
     void skip(int &l){

        if(l>=n) return ;
        int prev = global[l];
        if(l<n-1)l++;
        while(l<n and global[l]==prev)l++;

    }

};
