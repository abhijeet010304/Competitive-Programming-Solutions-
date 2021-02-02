// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{


	public:
	int maxSumIS(int arr[], int n)
	{
	    vector<pair<int,int>> ans;
	    int i,j;
	    for(i=0;i<n;i++){
	        ans.push_back({1,arr[i]});
	    }
	    for(i=0;i<n;i++){
	        for(j=0;j<i;j++){
	            if(arr[i]>arr[j]){
	                ans[i].first = max(ans[j].first+1,ans[i].first);
	                ans[i].second = max(ans[i].second,ans[j].second+arr[i]);

	            }
	        }
	    }
	    int sum =0;
	    for(i=0;i<n;i++){
	        sum = max(sum,ans[i].second);
	    }
	    return sum;

	}
};

// { Driver Code Starts.
int main()
{


   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];



	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";

    }
    return 0;
}

  // } Driver Code Ends
