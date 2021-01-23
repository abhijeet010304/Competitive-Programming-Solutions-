bool backtrack(vector<string> st,string s, unordered_map<string, bool> &check){
    if(s.length()==0){

        return true;
    }
    //in geeks for geeks we want all solutions so commenting the already checked string
    // in leetcode it gives TLE
    if(check[s]==true)return false;
    check[s] = true;

    for(auto x: st){
        if(s.find(x)==0){
            // temp.push_back(x);
            if(backtrack(st,s.substr(x.length()),check))return true;
            // temp.pop_back();
        }
    }
    return false;
}
//User function template for C++

// A : given string to search
// B : vector of available strings

int wordBreak(string A, vector<string> &B) {
    //code here

    unordered_map<string, bool> check;

    return backtrack(B,A, check);

}
