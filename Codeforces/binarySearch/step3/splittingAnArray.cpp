#include<bits/stdc++.h>
// #include"debug.cpp"
using namespace std;
vector<int> arr(100005);
bool condition(long long int sum,int k,int n ){
    long long int count = 0  ,i,tempsum=0;
    for(i=0;i<n;i++){
        tempsum+=arr[i];
        if(tempsum>sum){
            count++;
            tempsum = arr[i];
        }
    }

    if(count<k)return true;
    else return false;
}
int main(){

    int n,k,i;
    cin>>n>>k;
    for(i =0;i<n;i++){
        cin>>arr[i];
    }
    long long int left = *max_element(arr.begin(),arr.end())-1;
    long long int right = 1e15;
    while(left+1<right){
        long long int mid = left+(right- left )/2;

        if(condition(mid,k,n)){
            right = mid;
        }
        else left = mid;
    }
    cout<<right<<"\n";
    return 0;
}
