class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size();
        int c = board[0].size();
        vector<int> row = {-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> col = {0, 1, 1,1, 0, -1,-1,-1};
        vector<vector<int>>ans(r, vector<int> (c,-1));
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                int count = 0 ;
                for(int k = 0;k<8;k++){
                    int nr = i+row[k];
                    int nc = j+col[k];
                    if(valid(nr, nc, r, c)){
                        count+=board[nr][nc];
                    }
                   
                }
                // cout<<i<<" "<<j<<" "<< board[i][j]<< " "<<count<< endl;
                 if(board[i][j]==0 ){
                     if(count==3)
                        ans[i][j] = 1;
                     else ans[i][j] = 0;
                 }
                 else {
                        if(count<2)ans[i][j] = 0;
                        else if(count==2 or count==3)ans[i][j] = 1;
                        else ans[i][j] = 0;

                 }
                    // cout<<i<<" "<<j<<" "<< ans[i][j]<< " "<<count<< endl;
                
               
            }
        }
        board = ans;
    }
    bool valid(int i, int j, int r, int c){
        return (i>=0 and i<r and j>=0 and j<c);
    }
};