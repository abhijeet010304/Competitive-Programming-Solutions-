/*
Brute force using sorting
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int >st;
        for(auto x: nums)st.insert(x);
        vector<int > temp;
        for(auto x: st)temp.push_back(x);
          if(!temp.size())return 0;
        if(temp.size()==1)return 1;
        sort(temp.begin(),temp.end());
        for(auto x: temp) cout<<x<<" ";
        int i,p1 = 0,p2 =1;
        int n = temp.size();
        int ans =0;
        cout<<"\n";
        while(p2<n){

            while(p2<n and temp[p2]==temp[p2-1]+1)p2++;
            ans = max(ans,p2-p1);
            cout<<ans<<"\n";
            p1 = p2;
            p2++;
        }
        return ans ;
    }
};

/*
using map
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(),i;
        unordered_map<int,int> mp;
        for(i=0;i<n;i++){
            mp[nums[i]]=1;
        }
        int ans = 0;
        for(i=0;i<n;i++){

            if(mp[nums[i]-1]!=1){
                int check = nums[i],count =0;

                while(mp[check]==1){

                    check++;
                    count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};


/*
using set
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(),i;
        unordered_set<int> st;
        for(i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int ans = 0;
        for(i=0;i<n;i++){

            if(st.count(nums[i]-1)==0){
                int check = nums[i],count =0;

                while(st.count(check)==1){

                    check++;
                    count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};
