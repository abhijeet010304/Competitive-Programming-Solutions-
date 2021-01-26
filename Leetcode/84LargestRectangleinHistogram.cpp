class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsl,nsr;
        int n = heights.size();

        nsl = next_sl(heights);
        nsr = next_sr(heights);

        int ans = -1;
        for(int i=0;i<n;i++){
            int len = nsr[i]-nsl[i]-1;
            int val = heights[i];
            ans = max(ans,len*val);
        }

        return ans;
    }
    vector<int> next_sr(vector<int> arr) {
        int n = arr.size();
        vector<int> ret(n);
        stack<int> st;
        st.push(n-1);
        ret[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(st.size() and arr[i]<=arr[st.top()])st.pop();
            if(st.size()){
                ret[i] = st.top();

            }
            else{
                ret[i]=n;

            }
            st.push(i);
        }
        return ret;

    }
    vector<int> next_sl(vector<int> arr) {
        int n = arr.size();
        vector<int> ret(n);
        stack<int> st;
        st.push(0);
        ret[0]=-1;
        for(int i=1;i<n;i++){
            while(st.size() and arr[i]<=arr[st.top()])st.pop();
            if(st.size()){
                ret[i] = st.top();

            }
            else{
                ret[i]=-1;

            }
            st.push(i);
        }
        return ret;

    }
};
