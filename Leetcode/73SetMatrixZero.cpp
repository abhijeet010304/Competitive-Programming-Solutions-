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

/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(),col = matrix[0].size(),i,j;
        vector<int> r1,c1;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(matrix[i][j]==0){
                    r1.push_back(i);
                    c1.push_back(j);

                }
            }
        }
        int n = r1.size();
        for(int l=0;l<n;l++){
           int i = r1[l];
           int j = c1[l];
             for(int k = 0;k<col;k++){
                matrix[i][k]=0;

            }

            for(int k = 0;k<row;k++){
                matrix[k][j]=0;

            }

        }




    }
};
*/



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(),col = matrix[0].size(),i,j;
        if(row==1){
            bool found =false;
            for(i=0;i<col;i++){
                if(matrix[0][i]==0)found =true;
            }
            if(found){
                for(i=0;i<col;i++){
                    matrix[0][i]=0;
                }
            }
        }

        else if(col==1){
            bool found =false;
            for(i=0;i<row;i++){
                if(matrix[i][0]==0)found =true;
            }
            if(found){
                for(i=0;i<row;i++){
                    matrix[i][0]=0;
                }
            }
        }
        else{
            bool found1 = false,found2 = false;
            for(i=0;i<col;i++){
                 if(  matrix[0][i]==0) found1=true;
            }
            for(i=0;i<row;i++){
                 if(  matrix[i][0]==0) found2=true;
            }

            for(i=1;i<row;i++){
                for(j=1;j<col;j++){
                    if(matrix[i][j]==0){
                        matrix[i][0]=0;
                        matrix[0][j]=0;
                    }

                }
            }

            for(i=row-1;i>=0;i--){
                for(j=col-1;j>=0;j--){
                    if(matrix[i][0]==0 or matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
            if(found1){
                for(i=0;i<col;i++)matrix[0][i]=0;
            }
             if(found2){
                for(i=0;i<row;i++)matrix[i][0]=0;
            }
        }
    }
};
