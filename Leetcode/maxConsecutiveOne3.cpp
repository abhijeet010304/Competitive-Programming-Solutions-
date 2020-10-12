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

void printdq(auto dq){
	while(dq.size()>0){
		cout<<dq.front()<<" ";
		dq.pop_front();
	}
	cout<<"\n";
}
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
	cin>>n>>k;
	vll arr(n);
	for(i=0;i<n;i++)cin>>arr[i];

	n = arr.size();
	int p1 = 0,p2 = 0;
	int check = 0,ans = 0,count = 0, diff = 0;
	deque<int> dq;
	vector<int> one;
	if(k==0){
		while(p1<n){
			if(arr[p1]==1){
				count++;

			}
			else {
				ans = max(ans,count);
				count = 0;
			}
			p1++;
		}
		ans = max(ans,count);
		return ans ;
	}
	while(p1<n){

		if(arr[p1]==1){
			// reach(1);
			count++;
			ans = max(count ,ans);
			one.pb(p1);

		}
		else if(p1<n and check < k and arr[p1]==0){
			check++;
			// reach(2);
			count++;
			ans = max(count ,ans);
			dq.push_back(p1);

		}
		else if(p1<n and arr[p1]==0){
			int fr = dq.front();
			if(dq.size()>0){
				dq.pop_front();
				// count--;
			}
			// debug(fr);
			diff = p1-fr;
			if(diff == k){
				// reach(3);

				p2 = dq.front();
				ans = max(count ,ans);
				count = k;
				check = k;

			}
			else{
				// reach(4);
				dq.push_back(p1);
				count  = p1 - fr;
				ans = max(count ,ans);

			}
		}
		// debug(p1,ans,count,check  );
		// printdq(dq);
		p1++;
		cout<<"\n";
	}
	cout<<ans<<"\n";


}
