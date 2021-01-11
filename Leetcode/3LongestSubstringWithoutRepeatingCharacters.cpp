class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int p1 = 0, p2 = 0;
        int ans = 0,n = s.length();
        set<char> st;
        while(p2<n){
            if(st.count(s[p2])!=0){
                while(p1<n and st.count(s[p2])!=0){
                    st.erase(s[p1]);
                    p1++;
                }

            }

            st.insert(s[p2]);
            ans = max(ans,p2-p1+1);
            p2++;

        }
        return ans;
    }
};
