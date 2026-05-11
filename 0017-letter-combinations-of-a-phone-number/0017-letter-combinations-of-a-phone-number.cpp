class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int,string>mpp;
        string ds="";
        int index;
        vector<string>results;
        mpp[2]="abc";
        mpp[3]="def";
        mpp[4]="ghi";
        mpp[5]="jkl";
        mpp[6]="mno";
        mpp[7]="pqrs";
        mpp[8]="tuv";
        mpp[9]="wxyz";
        solve(digits,0,mpp,ds,results);
        return results;
    }
    void solve(string digits,int index, map<int,string>&mpp,string ds,vector<string>&results){
        if(index==digits.size()){
            results.push_back(ds);
            return;
        }
        int digit=digits[index]-'0';
        string letters=mpp[digit];
        for(int i=0;i<letters.size();i++){
            ds.push_back(letters[i]);
            solve(digits, index+1, mpp, ds, results);
            ds.pop_back();
        }
    }
};