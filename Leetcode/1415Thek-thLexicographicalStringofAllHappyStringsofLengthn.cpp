
class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> result;
        string temp="";
        vector<char> choice={'a','b','c'};
        //0 is used to check that we are inserting only different character everytime to form string
        backtrack(n,result,temp,'0',choice);
        sort(result.begin(),result.end());
        if(result.size()<k)return "";
        else return result[k-1];


    }

    void backtrack(int n ,vector<string>&result, string &temp, char dif,vector<char>choice){
        if(temp.length()==n){

            result.push_back(temp);
        }
        if(temp.length()>n)return ;

        for(int i=0;i<3;i++){
            if(choice[i]!=dif){
                temp+=choice[i];
                backtrack(n,result,temp,choice[i],choice);
                temp.erase(temp.size()-1,1);
            }
        }
    }
};
