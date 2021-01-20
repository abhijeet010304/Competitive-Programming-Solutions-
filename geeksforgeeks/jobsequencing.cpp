// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include<bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};


 // } Driver Code Ends


// Prints minimum number of platforms reqquired

bool sortcol(Job &a,Job&b){
    if(a.profit>b.profit)return true;
    else return false;
}
pair<int,int> JobScheduling(Job arr[], int n)
{
    // your code here
    sort(arr,arr+n,sortcol);
    int i;
    // for(i=0;i<n;i++){
    //     cout<<arr[i].id<<" "<<arr[i].dead<<" "<<arr[i].profit<<"\n";
    // }
    int ans[100+1];
    memset(ans,-1,sizeof(ans));

    int pr = 0;
    for(i=0;i<n;i++){
        int p1 = arr[i].dead;
        while(p1>0 and ans[p1]!=-1){
            p1--;
        }

        if(p1>0){
            ans[p1] = arr[i].id;
            pr+=arr[i].profit;
        }

    }
    int co =0;
    for(i=0;i<101;i++){
        if(ans[i]!=-1)co++;
    }
    pair<int,int> ret  = {co,pr};
    return ret;
}



// { Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    //testcases
    cin >> t;

    while(t--){
        int n;

        //size of array
        cin >> n;
        Job arr[n];

        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        //function call
        pair<int,int> ans = JobScheduling(arr, n);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
	return 0;
}


  // } Driver Code Ends
