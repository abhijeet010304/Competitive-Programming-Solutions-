#include<bits/stdc++.h>
using namespace std ;
	#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#define lli long long int
	#define ulli unsigned long long int
	#define ff first
	#define ss second
	#define mp make_pair
	#define pb push_back
	#define pf pop_front()
	#define lb lower_bound
	#define ub upper_bound
	#define bs binary_search
	#define fo(i,a,b) for(lli i=a;i<b;i++)
	#define fop(i,a,b) for(lli i=a;i<=b;i++)
	#define all(v) v.begin(), v.end()
	#define mod 1000000007
	#define inf 100000000000000000
	#define lld long double
	#define pll pair<long long int,long long int>
	#define pii pair<int,int>
	#define vll vector<lli>
	#define vii vector<int>
	#define endl '\n'
	#define pie  acosl(-1.0);
	#define setp(k, x) fixed << setprecision(k) << (x)
	#define deb(x) cerr << #x << ": " << x << " " << endl;
	#define reach(x) cout << "m here-" <<#x<<" ..."<<"\n";
	#define printa(a,n) for(lli i=0;i<n;i++) cout<<a[i]<<" "; cout<<"\n";
  #define printv(a) for(lli i=0;i<a.size();i++) cout<<a[i]<<" "; cout<<"\n";
	bool sortcol( const vector<lli>& v1, const vector<lli>& v2 ) //sort on basis of column //use- sort(vect.begin(), vect.end(),sortcol);
      { return v1[1] < v2[1]; }//[] o based indexing in column
	bool sortpair(const pair<lli, lli> &a, const pair<lli, lli> &b)
			{return a.second < b.second;}
	struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// if you want to use pair inside  unordered_map
struct hash_pair {
template <class T1, class T2>
size_t operator()(const pair<T1, T2>& p) const
{
	auto hash1 = hash<T1>{}(p.first);
	auto hash2 = hash<T2>{}(p.second);
	return hash1 ^ hash2;
}
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
////////////////////////////////////////////////////////////

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "debug.cpp"
#endif

//////////////////////////////////////////////////////////////////////////////////////////////
void solve();
//////////////////////////////////////////////////////////////////////////////////////////////


int main ()
{
	// fastio

 	lli  t;
 	cin>>t;
 	while(t--)
 	{
	solve();

 	}
}
///////////////////////////////////////////
void solve()
{
	lli n,i,d,a,b,c,j,k;
    cin>>n;
    vector<int> arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    int found = 0,end = 0,start = 0,count =0 ,ans = 0,check =0;//0= checking for greater in next
    n = arr.size();
    if(n==1){
        cout<<1<<"\n";
        return ;
    }
    while(end<n-1){

        if(arr[end]==arr[end+1]){
            // reach(1)
            ans = max(ans,count);
            count = 0;
            found = 0;
            end++;
        }
        else{
            if(found==0){
                if(arr[end]<arr[end+1]){
                    // reach(2);
                    found = 1;
                    check = 0;
                    count+=2;
                }
                else{
                    // reach(3);
                    found = 1;
                    check = 1;
                    count+=2;
                }
            }
            else{
                if(check==0){
                    if(arr[end]<arr[end+1]){
                        // reach(4);
                        ans = max(ans,count);
                        count = 2;
                        found = 1;

                    }
                    else if(arr[end]==arr[end+1]){
                        // reach(9);
                        count = 0;
                        found = 0;
                    }
                    else {
                        // reach(5);
                        count++;
                        check = 1;
                        ans = max(ans,count);
                    }
                }
                else{
                    if(arr[end]>arr[end+1]){
                        // reach(6);
                        ans = max(ans,count);
                        count = 2;
                        found = 1 ;

                    }
                    else if(arr[end]==arr[end+1]){
                        // reach(8);
                        count = 0;
                        found = 0;
                    }
                    else {
                        // reach(7);
                        count++;
                        check=0;
                        ans = max(ans,count);

                    }
                }
            }
            end++;
        }

        // debug(end,ans,count,check,found);

    }
    cout<<ans<<"\n";





}
