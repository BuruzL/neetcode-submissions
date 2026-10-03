class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> res;
       vector<int> sub;
       backtrack(nums, res, 0, sub);
       return res;
    }

    void backtrack(vector<int> &nums, vector<vector<int>> &res, int i , vector<int> &sub){
        if(i>=nums.size()){
            res.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        backtrack(nums, res, i+1, sub);
        sub.pop_back();
        backtrack(nums, res, i+1, sub);
    }
    
};