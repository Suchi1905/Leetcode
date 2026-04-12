class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int index;
        vector<int>ds;
        vector<vector<int>>results;
        sort(candidates.begin(), candidates.end());
        results=solve(candidates,0,target,ds,results);
        return results;
    }
    vector<vector<int>>solve(vector<int> &candidates,int index,int target,vector<int>ds,vector<vector<int>>results){
        if(target==0){
            results.push_back(ds);
            return results;
        }
        if(index >= candidates.size())
        return results;
        if(candidates[index]<=target){
            if(index==0 || candidates[index-1] != candidates[index] || (ds.size() && ds.back()==candidates[index-1])){
            ds.push_back(candidates[index]);
            results=solve(candidates,index+1,target-candidates[index],ds,results);
            ds.pop_back();
            }
        }
        int next = index;
        while(next+1 < candidates.size() && candidates[next] == candidates[next+1])
            next++;
        results=solve(candidates,next+1,target,ds,results);
        return results;
    }
};