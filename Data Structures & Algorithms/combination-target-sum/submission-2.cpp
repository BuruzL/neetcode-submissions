class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target){
        vector<vector<int>> res;
        vector<int> sub;
    int i=0;
backtrack(res, nums, sub, target, i);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<int>& nums, vector<int> &sub, int target, int i){
        if(target==0){
            res.push_back(sub);
            return;
        }

        if(target<0 || i>=nums.size()){
            return;
        }
        
        sub.push_back(nums[i]);
        backtrack(res, nums, sub, target-nums[i], i);
        sub.pop_back();
        backtrack(res, nums, sub, target, i+1);
    }
 
};
