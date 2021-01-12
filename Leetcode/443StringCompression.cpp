
class Solution {
public:
    int compress(vector<char>& chars) {
        int p1=0,p2=0,n = chars.size();
        int ans =0;
        while(p2<n){
            int count = 0;
            while(p2<n and chars[p1]==chars[p2]){
                count++;
                p2++;

            }
            if(count==1){
                ans += count ;
                p1 = p2;
            }
            else {


                string tempans = to_string(count);

                int len = tempans.length();
                ans += len+1;

                if(p1<p2)
                    p1++;
                for(int i =0;i<len;i++){
                    chars[p1++] = tempans[i];
                }

                if(p1<p2)
                    chars.erase(chars.begin()+p1,chars.begin()+p2);

                p2 = p1;
            }


            n = chars.size();
        }


        return chars.size();
    }

};
