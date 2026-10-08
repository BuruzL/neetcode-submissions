class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        int i=0; 
        vector<string> sub;
        
            backtrack(res, sub,0, s);
               return res;
        }
     

          void backtrack(vector<vector<string>> &res, vector<string> &sub, int start, string s){
        if(start==s.size()){
            res.push_back(sub);
            return;
        }
      
        for(int j=start; j<s.size(); j++){
            if(isPalindrome(s, start, j)){
        sub.push_back(s.substr(start, j-start+1));
        backtrack(res, sub, j+1, s);
        sub.pop_back();
            }
    }
          }
    
    bool isPalindrome(string &s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
  
};
