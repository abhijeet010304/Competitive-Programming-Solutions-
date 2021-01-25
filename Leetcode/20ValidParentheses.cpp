class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.length()==0 or s.length()%2!=0)return false;
        for(int i=0;i<s.length();i++){
            if(st.size()==0){
                st.push(s[i]);
                continue;
            }
            else{
                char ch = s[i];
                if(st.size()){
                    if(ch==')' and st.top()=='(')st.pop();
                    else if(ch=='}' and st.top()=='{')st.pop();
                    else if(ch==']' and st.top()=='[')st.pop();
                    else st.push(ch);
                }
                else{
                    st.push(ch);
                }
            }
        }
        if(st.size())return false;
        else return true;
    }
};
