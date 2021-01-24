class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> diag;
        int row = mat.size();
        int col = mat[0].size();
        for(int i=0;i<row+col-1;i++){
            vector<int> temp;
            diag.push_back(temp);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int ind = i-j;
                diag[ind+col-1].push_back(mat[i][j]);
            }
        }
        for(int i=0;i<row+col-1;i++){
            sort(diag[i].begin(),diag[i].end(),greater<>());
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int ind = i-j+col-1;
                mat[i][j] = diag[ind][diag[ind].size()-1];
                diag[ind].pop_back();
            }
        }
        return mat;


    }
};
