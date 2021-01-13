class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int start = 0,n = people.size();
        int end = n-1;
        int count = 0;
        while(start<=end){

            if (start==end){
                count++;
                break;
            }
            else if(end-start==1){
                if(people[start]+people[end]<=limit)count++;
                else count+=2;
                break;
            }
            else if(people[start]+people[end]<=limit){
                start++;
                end--;
                count+=1;
            }
            else {
                end--;
                count+=1;

            }


        }
        return count;



    }
};
