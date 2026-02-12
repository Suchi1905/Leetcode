class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        int open,close;
        string curr;
        solve(0,0,n,"",result);
        return result;
    }
    void solve(int open,int close,int n,string current,vector<string>&result)
    {
        if(current.length()==2*n){
            result.push_back(current);
            return;
        }
        if(open<n){
            solve(open+1,close,n,current+"(",result);
        }
        if(close<open){
            solve(open,close+1,n,current+")",result);
        }
    }
};