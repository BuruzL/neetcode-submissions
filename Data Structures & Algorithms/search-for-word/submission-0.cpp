class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool flag=false;
        int rows=board.size();
        int cols=board[0].size();
        vector<char> sub;
        
        for(int r=0; r<board.size(); r++){
            for(int c=0; c<board[0].size(); c++){
                if(backtrack(board, word, 0, r,c, sub, flag)){
                    return true;
                }
            }
        }
        return false;
    }
    bool backtrack(vector<vector<char>> &board, string &word, int i, int row, int col, vector<char> &sub, bool flag){
        if(i==word.length()){
            return true;
        }
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || word[i]!=board[row][col]){
            return false;
        }

        sub.push_back(board[row][col]);
        char temp=board[row][col];
        board[row][col]='#';
        flag=(
            backtrack(board, word, i+1, row+1, col, sub, flag) ||
            backtrack(board, word, i+1, row-1, col, sub, flag) ||
            backtrack(board, word, i+1, row, col+1, sub, flag) ||
            backtrack(board, word, i+1, row, col-1, sub, flag)       
            );
            board[row][col] = temp;
        sub.pop_back();
        return flag;

    }
};
