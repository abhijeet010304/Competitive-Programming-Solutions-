/*check with example like stack = [8,6,4,2]; and 8 = top
arr[i] = 7
then apply the conditions

and right operations me right se array start karnge
left operations me left se
*/
#include<bits/stdc++.h>
#include"debug.cpp"
using namespace std;
vector<int>  next_gr(vector<int> arr);
vector<int>  next_sr(vector<int> arr);
vector<int>  next_gl(vector<int> arr);
vector<int>  next_sl(vector<int> arr);

int main(){
    int n ;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ngr = next_gr(arr);
    vector<int> nsr = next_sr(arr);
    vector<int> ngl = next_gl(arr);
    vector<int> nsl = next_sl(arr);
    cout<<"NGR:\n";
    print(ngr);
    cout<<"NSR:\n";
    print(nsr);
    cout<<"NGL:\n";
    print(ngl);
    cout<<"NSL:\n";
    print(nsl);
    return 0;
}

vector<int> next_gl(vector<int> arr) {
    int n = arr.size();
    vector<int> ret(n);
    stack<int> st;
    st.push(arr[0]);
    ret[0]=-1;
    for(int i=1;i<n;i++){
        while(st.size() and arr[i]>=st.top())st.pop();
        if(st.size()){
            ret[i] = st.top();

        }
        else{
            ret[i]=-1;

        }
        st.push(arr[i]);
    }
    return ret;

}
vector<int> next_sl(vector<int> arr) {
    int n = arr.size();
    vector<int> ret(n);
    stack<int> st;
    st.push(arr[0]);
    ret[0]=-1;
    for(int i=1;i<n;i++){
        while(st.size() and arr[i]<=st.top())st.pop();
        if(st.size()){
            ret[i] = st.top();

        }
        else{
            ret[i]=-1;

        }
        st.push(arr[i]);
    }
    return ret;

}


 next_sr(vector<int> arr) {
    int n = arr.size();
    vector<int> ret(n);
    stack<int> st;
    st.push(arr[n-1]);
    ret[n-1]=-1;
    for(int i=n-2;i>=0;i--){
        while(st.size() and arr[i]<=st.top())st.pop();
        if(st.size()){
            ret[i] = st.top();

        }
        else{
            ret[i]=-1;

        }
        st.push(arr[i]);
    }
    return ret;

}


vector<int>  next_gr(vector<int> arr){
    int n = arr.size();
    vector<int> ret(n);
    stack<int> st;
    st.push(arr[n-1]);
    ret[n-1] = -1;
    for(int i=n-2;i>=0;i--){
        while(st.size() and arr[i]>=st.top())st.pop();
        if(st.size()==0){
            ret[i]=-1;
        }
        else ret[i]=st.top();
        st.push(arr[i]);
    }
    return ret;
}
