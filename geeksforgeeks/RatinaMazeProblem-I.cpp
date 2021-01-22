// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
int xc[]={0,1,0,-1};
int yc[]={1,0,-1,0};

bool isvalid(int i,int j,int n,int m[MAX][MAX]){
    if(i>=0 and j>=0 and i<n and j<n and m[i][j]!=0)return true;
    else return false;
}

void backtrack(int m[MAX][MAX],int n, vector<string> &ans,string &temp,vector<vector<bool>>&vis,int x,int y,char ch){
    if(x==n-1 and y==n-1 ){
        ans.push_back(temp);
        return ;
    }

    for(int i=0;i<4;i++){
        if(isvalid(x-xc[i],y-yc[i],n,m) and !vis[x-xc[i]][y-yc[i]] ){


            if(i==0){
                ch = 'L';

            }
             if(i==1){
                ch = 'U';
            }
             if(i==2){
                ch = 'R';
            }
             if(i==3){
                ch = 'D';
            }
            vis[x-xc[i]][y-yc[i]] = true;
            temp+=ch;
            backtrack(m,n,ans,temp,vis,x-xc[i],y-yc[i],ch);
            vis[x-xc[i]][y-yc[i]] = false;
            temp.erase(temp.length()-1,1);
        }
    }





}
vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here
    vector<string> ans;
    string temp ="";
    vector<vector<bool>>vis;
    if(m[0][0]==0 or m[n-1][n-1]==0)return ans;
    for(int i=0;i<n;i++){
        vector<bool>tem;
        for(int j=0;j<n;j++)tem.push_back(false);
        vis.push_back(tem);
    }
    vis[0][0] = true;
    backtrack(m,n,ans,temp,vis,0,0,'$');
    sort(ans.begin(),ans.end());
    return ans;


}
