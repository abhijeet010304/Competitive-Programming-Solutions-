class Solution {
public:
    int countVowelStrings(int n) {
        int sum = 0,ret;
        int a=1,b=1,c=1,d=1,e=1;
        for(int i=0;i<n;i++){


            a = a+b+c+d+e;
            sum = a;

            b = b+c+d+e;
            c = c+d+e;
            d = d+e;
            e = e;

        }
        return sum;
    }
};
