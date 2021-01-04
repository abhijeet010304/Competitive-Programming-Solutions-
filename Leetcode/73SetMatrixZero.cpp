//approach 1
/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(),col = matrix[0].size(),i,j;
        vector<vector<bool>> vis(row,(vector<bool>(col,false)));
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(matrix[i][j]==0)vis[i][j]=true;
            }
        }

        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(vis[i][j]){
                    for(int k = 0;k<col;k++){
                        matrix[i][k]=0;

                    }
                    for(int k = 0;k<row;k++){
                        matrix[k][j]=0;

                    }
                }
            }
        }
    }
};
*/
