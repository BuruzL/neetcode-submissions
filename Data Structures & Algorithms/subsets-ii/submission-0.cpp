class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub; vector<vector<int>> res;
        int i=0;
        sort(nums.begin(), nums.end());
        backtrack(res, sub, nums, 0);
        return res;
    }
    void backtrack(vector<vector<int>> &res, vector<int> &sub,vector<int> &nums, int start){
       
            res.push_back(sub);
            
    for(int i=start; i<nums.size(); i++){
        if(i>start && nums[i]==nums[i-1]){
            continue;
        }
        sub.push_back(nums[i]);
        backtrack(res, sub, nums, i+1);
        sub.pop_back();
    }
    }
};
