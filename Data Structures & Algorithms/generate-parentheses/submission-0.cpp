//22. Generate Parentheses
//https://leetcode.com/problems/generate-parentheses/description/?envType=daily-question&envId=2026-10-02
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0,0,n);
        return res;
    }
    void backtrack(vector<string> &res, string cur_str, int open, int close, int max){
        if(cur_str.length()>=max*2){
            res.push_back(cur_str);
            return;
        }
        if(open<max){
            backtrack(res, cur_str+'(', open+1, close, max);
        }
        if(close<open){
            backtrack(res, cur_str+')', open, close+1, max);
        }
    }
};