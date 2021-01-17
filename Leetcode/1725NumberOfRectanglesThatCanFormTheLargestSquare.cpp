class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int i,j,n = rectangles.size(),minn = -1;

        map<int,int> mp;
        int ans = -1,val = -1e9;
        for(i=0;i<n;i++){
            minn = min(rectangles[i][0],rectangles[i][1]);
            val = max(minn,val) ;

            mp[minn]++;
        }


       return mp[val];

    }
};
