class Solution {
public:
    vector<int> xc = {1,0,-1,0};
    vector<int> yc = {0,-1,0,1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = -1, right = 1e6;
        while(left+1<right){
            int mid = left+(right-left)/2;
            // cout<<left<<" "<<mid<<" "<<right<<"\n";
            if(condition(mid,heights)){
                right = mid;
            }
            else left = mid;
        }
        return right;
    }

    bool condition(int mid,vector<vector<int>> &heights){

        int row ,col;
        row = heights.size();
        col = heights[0].size();
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        if(dfs(mid,0,0,vis,row,col,heights))return true;
        else return false;
    }
    bool isvalid(int i,int j,int r,int c){
        if(i>=0 and j>=0 and i<r and j<c)return true;
        else return false;
    }
    bool dfs(int mid,int i,int j,vector<vector<bool>> &vis,int row, int col,vector<vector<int>> &heights ){
        // cout<<1<<"\n";
        vis[i][j]=true;
        if(i==row-1 and j==col-1)return true;
            for(int k=0;k<4;k++){
                int dx = i-xc[k];
                int dy = j-yc[k];
                if(isvalid(dx,dy,row,col) and !vis[dx][dy] and abs(heights[i][j]-heights[dx][dy])<=mid ){
                          if(dfs(mid,dx,dy,vis,row,col,heights))return true;
                }
            }

        return false;

  }
};
