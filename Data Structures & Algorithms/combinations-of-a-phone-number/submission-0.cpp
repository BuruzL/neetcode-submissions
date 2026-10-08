class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string sub;
        if (digits.empty()) return res;
        unordered_map<char, string> mp={
             {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
        };
        backtrack(res, 0, sub, digits, mp);
        return res;
    }
    void backtrack(vector<string> &res, int i, string sub, string &digits, unordered_map<char, string> &mp){
        if(i==digits.size()){
            res.push_back(sub);
            return;
        }

        for(int J=0; J<mp[digits[i]].size(); J++){
            sub.push_back(mp[digits[i]][J]);
            backtrack(res, i+1, sub, digits, mp);
            sub.pop_back();
        }
    }
};
