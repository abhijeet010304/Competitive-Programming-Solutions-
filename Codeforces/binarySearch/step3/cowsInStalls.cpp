#include<bits/stdc++.h>
#include"debug.cpp"
using namespace std;
vector<int> arr(100005);
vector<int> dis(100005);
bool condition(int dist,int n,int k){
    int count = 1;
    int tempsum =0;
    for(int i =0;i<n-1;i++){
        tempsum+=dis[i];
        if(tempsum>=dist){
            tempsum = 0;
            count++;
        }
    }
    // debug(dist,count);
    if(count>=k)
        return true;
    else return false;

}
int main(){

    int n,k,i;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    arr.resize(n);
    dis.resize(n-1);


    sort(arr.begin(),arr.end());
    int left=1e9,right = 1e9;
    for(i=0;i<n-1;i++){
        dis[i] = arr[i+1]-arr[i];
        left = min(left,dis[i]);
    }
    // print(dis);

    while(left+1<right){
        int mid = left+(right-left)/2;
        // debug(left,mid,right);
        if (condition(mid,n,k)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout<<left<<"\n";
    return 0;

}
