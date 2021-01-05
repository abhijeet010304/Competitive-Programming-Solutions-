class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        if(n==1) {
            return intervals;
        }
        int start = 0,end = 0;
        vector<int> temp;
        vector<vector<int>> ret;
        int left  = intervals[start][0];
        int right = intervals[start][1];
        int pl= intervals[start][0],pr =  intervals[start][1];
        while(end<n){
            //condition ---
            left  = intervals[end][0];
            right = intervals[end][1];
            if(left<=pr){
                pr = max(pr,right);
                end++;
                continue;
            }
            temp.clear();
            temp.push_back(pl);
            temp.push_back(pr);
            ret.push_back(temp);
            pl = left;
            pr = right;


        }
        temp.clear();
            temp.push_back(pl);
            temp.push_back(pr);
            ret.push_back(temp);
            pl = left;
            pr = right;



        return ret;
    }
};
