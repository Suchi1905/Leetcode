class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>result;
        vector<int>ds;
        int sum,elements;
        int index;
        solve(k,n,0,1,0,result,ds);
        return result;
    }
    void solve(int k, int n,int sum,int index,int elements,vector<vector<int>>&result,vector<int>&ds){
        if(sum==n && elements==k ){
            result.push_back(ds);
            return;
        }
        if(sum>n || index>9 || elements>k){
            return;
        }
        else{
            ds.push_back(index);
            solve(k,n,sum+index,index+1,elements+1,result,ds);
            ds.pop_back();
            solve(k,n,sum,index+1,elements,result,ds);
        }
    }
};