class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp());
        int mini = intervals[0][0];
        int maxi = intervals[0][1];
        int sz = intervals.size();
        vector<vector<int>> ans;
        for(int i = 1;i<sz;i++){
            if(intervals[i][0]<=maxi){
                maxi = max(intervals[i][1], maxi);
            }
            else{
                ans.push_back({mini, maxi});
                
                 mini = intervals[i][0];
                 maxi = intervals[i][1];
            }
            
        }
        ans.push_back({mini, maxi});
        return ans;
    }
    class comp {
    public:
        bool operator()(vector<int> &a, vector<int> &b) {
            return a[0] < b[0] ; 
        }
    };
};