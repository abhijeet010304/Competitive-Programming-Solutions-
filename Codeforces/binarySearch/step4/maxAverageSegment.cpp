#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
vector<double> arr(100005);
int r,l;
bool condition(double mid,int n,int d){
    vector<double> temp(n),pre(n),minn(n);
    int i ;
    for(i=0;i<n;i++){
        temp[i]=arr[i]-mid;

    }
    for(i=0;i<n;i++){
        if(i==0){
            pre[i]=temp[i];
            minn[i]=0;
        }
        else{
             pre[i]=temp[i]+pre[i-1];
             if(pre[i]<pre[minn[i-1]]){
                 minn[i]=i;
             }
             else minn[i] =minn[i-1];
        }

    }
    if(pre[d-1]>=0){
        l = 0;
        r = d-1;
        return true;
    }
    for(i=d;i<n;i++){

            if(pre[i]>=0){
                l = 0;
                r = i;
                return true;
            }
            if(pre[minn[i-d]]<=pre[i]){
                l = minn[i-d]+1;
                r = i;
                return true;
            }


    }
    return false;
}

int main(){
    int n,d,i;
    cin>>n>>d;
    arr.resize(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    double left = *min_element(arr.begin(),arr.end()),right = *max_element(arr.begin(),arr.end());
    for(i=0;i<100;i++){
        double mid = (left+right)/2;

        if (condition(mid,n,d)) {
            left = mid;
        } else {
            right = mid;
        }

    }
    cout<<l+1<<" "<<r+1<<"\n";

    return 0;
}
