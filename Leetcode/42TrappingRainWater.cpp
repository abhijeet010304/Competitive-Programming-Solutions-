class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        if(n<=2)return 0;
        vector<int> next_greater = next_g(height);
        vector<int> prev_greater = prev_g(height);

        int i,j,p1 = n-1,p2;
        for(i=0;i<n-1;i++){
            if(height[i]>height[i+1]){
                p1 = i;
                p2 = i+1;
                break;
            }
        }
        if(p1>=n-2)return 0;
        int lar;

        while(p1<n){
            if(next_greater[p1]>0){
                p2 = next_greater[p1];
                int currmax = height[p1];
                while(p1<n and p1!=p2){
                    ans+= currmax-height[p1];
                    p1++;
                }

            }
            else{
                lar = p1;
                break;
            }
        }
        //after finding amount of water trappend upto max height
        // calculate from the left it would be easier;
        if(p1>=n-2)return ans;
        else{
            p1 = n-1;
            while(p1>lar){
                if(prev_greater[p1]>=0){
                    p2 = prev_greater[p1];
                    int currmax = height[p1];
                    while(p1<n and p1!=p2){
                        ans+= currmax-height[p1];
                        p1--;
                    }

                }
                else{
                    p1--;

                }
            }

        }
        return ans ;

    }

    vector<int> next_g(vector<int> height){
        int n = height.size();
        stack<int> st;
        st.push(n-1);
        vector<int> ret(n);
        ret[n-1] = n;
        for(int i=n-2;i>=0;i--){
            if(height[i]>height[st.top()]){
                while(st.size() and height[i]>height[st.top()]){
                    st.pop();
                }

                if(st.size()){
                    ret[i] = st.top();

                }
                else ret[i] = n;
                st.push(i);
            }
            else{
                if(st.size())ret[i] = st.top();
                else{
                    ret[i] = n;
                }
                st.push(i);
            }
        }
        for(int i=0;i<n;i++){
            if(ret[i]>=n)ret[i]=-1;
            cout<<ret[i]<<" ";
        }
        cout<<"\n";
        return ret;



    }
    vector<int> prev_g(vector<int> height){
        int n = height.size();
        stack<int> st;
        st.push(0);
        vector<int> ret(n);
        ret[0] = n;
        for(int i=1;i<n;i++){
            if(height[i]>height[st.top()]){
                while(st.size() and height[i]>height[st.top()]){
                    st.pop();
                }

                if(st.size()){
                    ret[i] = st.top();

                }
                else ret[i] = n;
                st.push(i);
            }
            else{
                if(st.size())ret[i] = st.top();
                else{
                    ret[i] = n;
                }
                st.push(i);
            }
        }
        for(int i=0;i<n;i++){
            if(ret[i]>=n)ret[i]=-1;
            cout<<ret[i]<<" ";
        }
        cout<<"\n";
        return ret;



    }
};
