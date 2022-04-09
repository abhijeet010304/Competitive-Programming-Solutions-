class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int row = image.size();
        int col = image[0].size();
        for(int i = 0 ;i<row;i++){
            for(int j =0 ;j<col/2;j++){
                swap(image[i][j], image[i][col-1-j]);
                
            }
            for(int j = 0;j<col;j++){
                image[i][j]^=1;
            }
                
        }
        return image;
    }
};