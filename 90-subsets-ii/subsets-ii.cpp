class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       int index;
       vector<int>ds;
       vector<vector<int>>results;
       sort(nums.begin(), nums.end());
       solve(nums,0,ds,results); 
       return results;
    }
    void solve(vector<int>& nums,int index,vector<int>&ds,
    vector<vector<int>>&results){
        if(index==nums.size()){
            results.push_back(ds);
            return;
        }
        else{
                ds.push_back(nums[index]);
                solve(nums,index+1,ds,results);
                ds.pop_back();
                while(index+1<nums.size() && nums[index]==nums[index+1])
                index++;
                solve(nums,index+1,ds,results);
                }
    }
};