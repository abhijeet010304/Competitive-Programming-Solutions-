class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i =0 ;i<k;i++){
            vector<int> temp;
            for(int j = 0;j<row;j++){
                temp.push_back(grid[j][col-1]);
            }
            
            for(int j = col-2;j>=0;j--){
                for(int k =0 ;k<row;k++){
                    swap(grid[k][j], grid[k][j+1]);
                }
            }
            grid[0][0] = temp[row-1];
            for(int j = 0;j<row-1;j++){
                grid[j+1][0] = temp[j];
            }
        }
        return grid;
    }
    
};