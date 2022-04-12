class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> st;
//         for (auto x: nums)st.insert(x);
//         nums.clear();
//         int maxx = 0, current = 0;
//         for (auto x: st)nums.push_back(x);
//         for(int i=0;i<nums.size();i++){
//             int val = nums[i]-1;
//             if(st.count(val)){
//                 continue;
//             }
//             else{
//                 int check = nums[i];
//                 current =0;
//                 while(st.count(check)){
//                     current++;
//                     check++;
                    
//                 }
//                 maxx = max(current, maxx);
//             }
            
//         }
//         return maxx;
        
         unordered_set < int > hashSet;
  for (int num: nums) {
    hashSet.insert(num);
  }

  int longestStreak = 0;

  for (int num: nums) {
    if (!hashSet.count(num - 1)) {
      int currentNum = num;
      int currentStreak = 1;

      while (hashSet.count(currentNum + 1)) {
        currentNum += 1;
        currentStreak += 1;
      }

      longestStreak = max(longestStreak, currentStreak);
    }
  }

  return longestStreak;
    }
};