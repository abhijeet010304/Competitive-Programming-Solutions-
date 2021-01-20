// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends


//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

// function to return fractionalweights
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    vector<pair<double,int>> pw(n);
    int i;
    for(i=0;i<n;i++){
        pw[i] = {double(arr[i].value)/double(arr[i].weight),i};
    }
    double ret = 0;
    sort(pw.begin(),pw.end(),greater<pair<double,int>>());
    for(i=0;i<n;i++){
        int curw = pw[i].second;
        // cout<<curw<<" ";
        // cout<<W<<"\n";
        if(arr[curw].weight>W){
            int take = W;
            // cout<<take<<" "<<arr[curw].weight<<" "<<pw[i].first<<"\n";
            ret+= (take)*(pw[i].first);
            break;
        }
        else{
            W -= arr[curw].weight;
            ret+= arr[curw].value;
        }
    }
    return ret;
}

// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;

		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}

		//function call
		cout<<fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
