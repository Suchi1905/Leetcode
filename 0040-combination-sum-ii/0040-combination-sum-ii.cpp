class Solution {
public:
    
    void solve(vector<int>& candidates, int index, int target,
               vector<int>& ds, vector<vector<int>>& results){
        
        if(target == 0){
            results.push_back(ds);
            return;
        }
        
        for(int i = index; i < candidates.size(); i++){
            
            // skip duplicates
            if(i > index && candidates[i] == candidates[i-1])
                continue;
            
            if(candidates[i] > target)
                break;
            
            ds.push_back(candidates[i]);
            solve(candidates, i+1, target - candidates[i], ds, results);
            ds.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> results;
        vector<int> ds;
        
        sort(candidates.begin(), candidates.end());
        
        solve(candidates, 0, target, ds, results);
        
        return results;
    }
};