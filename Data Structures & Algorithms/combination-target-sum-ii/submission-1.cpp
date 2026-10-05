class Solution {
public:
vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target){
        res.clear();
        vector<int> sub;
    int i=0;
    sort(nums.begin(), nums.end());
backtrack(nums, sub, target, i, 0);
        return vector<vector<int>>(res.begin(), res.end());
    }
    void backtrack( vector<int>& nums, vector<int> &sub, int target, int i, int nu){
        if(target==nu){
            res.push_back(sub);
            return;
        }

        if(target<nu || i==nums.size()){
            return;
        }
        
        sub.push_back(nums[i]);
        backtrack( nums, sub, target, i+1, nu+nums[i]);
        sub.pop_back();
    int next=i+1;
    while(next<nums.size() && nums[i]==nums[next]){
        next++;
    }
        backtrack(nums, sub, target, next, nu);
    }
 
};
