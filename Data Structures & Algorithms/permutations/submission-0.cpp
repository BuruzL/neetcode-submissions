class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        int i=0;
                vector<bool> vis(nums.size(), false);
        backtrack(res, nums, sub, vis, 0);
        return res;
    }
    void backtrack(vector<vector<int>> & res, vector<int> &nums, vector<int> &sub, vector<bool> &vis, int i){
        if(sub.size()==nums.size()){
            res.push_back(sub);
            return;
        }
for(int i=0; i<nums.size(); i++){
        if(!vis[i]){
            sub.push_back(nums[i]);
            vis[i]=true;
            backtrack(res, nums, sub, vis, i+1);
            vis[i]=false;
            sub.pop_back();
          
        }
}
    }
};
