#include<bits/stdc++.h>
// #include"debug.cpp"
using namespace std;


vector<double> pos(100005),v(100005);
bool condition(double t,int n){
    double leftmost=-1e9,rightmost=1e9,templeft,tempright;
    for(int i = 0;i<n;i++){
        templeft = pos[i]-v[i]*t;
        tempright = pos[i]+v[i]*t;
        leftmost = max(leftmost,templeft);
        rightmost = min(rightmost,tempright);
    }
    if((rightmost-leftmost)>0){
        return true;
    }
    else return false;
}
int main(){
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>pos[i]>>v[i];
    }
    double left=-1e9,right=1e9;

    for(i=0;i<100;i++){
        double mid = left+ (right- left)/2;
        // debug(mid,left,right);
        if(condition(mid,n)){
            right = mid;
        }
        else left = mid;
    }
    cout<<setprecision(20)<<right<<"\n";
    return 0;

}
