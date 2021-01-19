class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        vector<int> ng(n);
        stack<int> st;
        ng[n-1] = -1;
        st.push(nums2[n-1]);
        map<int,int> mp;
        mp[nums2[n-1]]=-1;
        for(int i=n-2;i>=0;i--){
            // cout<<i<<"\n";
            if(nums2[i]>=st.top()){
                while(st.size() and nums2[i]>=st.top())st.pop();
                if(st.size()){
                    ng[i]=st.top();
                    mp[nums2[i]]=st.top();
                    st.push(nums2[i]);
                }
                else{
                    ng[i]=-1;
                    mp[nums2[i]]=-1;
                    st.push(nums2[i]);
                }
            }
            else{
                ng[i]=st.top();
                mp[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
        }
        vector<int> ret(nums1.size());
        int  i=0;
        for(auto x:nums1){
            ret[i++] = mp[x];
        }
        return ret;

    }
};
