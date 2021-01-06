#include<bits/stdc++.h>
#include"debug.cpp"
using namespace std;
#define it vector<int>:: iterator
void m_sort(it left, it right){
    if(right-left<=1) return ;
    it mid = left+(right - left)/2;
    debug(*left,*mid,*right);
    m_sort(left,mid);
    m_sort(mid,right);
    //code here 
    inplace_merge(left,mid,right);
}
void mergeSort(vector<int> arr){
    m_sort(arr.begin(),arr.end());
    print(arr);

}
int main(){
    int n,i;

    vector<int> arr ={5,2,6,1};

    mergeSort(arr);
}
/*
interval are [left,right)
and mid is not included for next interval
*/
