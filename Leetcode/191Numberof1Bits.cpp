class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count =0;
        string a = bitset<32>(n).to_string();
        // cout<<a<<"\n";
        for(auto c:a){
            if(c=='1')count++;
        }
        return count ;
    }
};
