#include<bits/stdc++.h>
#include "debug.cpp"
using namespace std;
#define ff first
#define ss second

vector<pair<double,double>> v(100005);
bool condition(double val,int n,int k){
    vector<double> temp(n);
    int i;
    for( i=0;i<n;i++){
        temp[i]=v[i].ff-(val*v[i].ss);
    }
    sort(temp.begin(),temp.end(),greater<>());
    double sum =0;
    for(i=0;i<k;i++){
        sum+=temp[i];
    }
    if(sum>=0)return true;
    else return false;

}
int main(){
    int n,k,i;
    cin>>n>>k;
    v.resize(n);
    for(i=0;i<n;i++){
        cin>>v[i].ff>>v[i].ss;
    }
    double left = 0,right = 1e5;
    for(i=0;i<100;i++){
        double mid = left+(right-left)/2;
        if(condition(mid,n,k)){
            left = mid;
        }
        else right = mid;
    }
    cout<<setprecision(20)<<left<<"\n";
}
