class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        backtrack(res, board, 0,n);
        return res;
    }

    void backtrack(vector<vector<string>> &res, vector<string> &board, int r, int n){
        if(r==n){
            res.push_back(board);
            return;
        }

        for(int cols=0; cols<n; cols++){
            if(isPossible(res, board, r, cols, n)){
                board[r][cols]='Q';
                backtrack(res, board, r+1, n);
                 board[r][cols]='.';
            }
        }

    }
    bool isPossible(vector<vector<string>> &res, vector<string> &board, int i, int j, int n){
        for(int k=0; k<n; k++){
            if(board[k][j]=='Q' && k!=i){
                return false;
            }
        }
        for(int k=0; k<n; k++){
            if(board[i][k]=='Q' && k!=j){
                return false;
            }
        }

        int dc[4]={-1,-1,1,1};
        int dr[4]={1,-1,1,-1};

        for(int d=0; d<4; d++){
            int c=j+dc[d];
            int r=i+dr[d];
            while(r>=0 && c>=0 && r<n && c<n){
                if(board[r][c]=='Q')return false;

                r+=dr[d];
                c+=dc[d];
            }
        }
        return true;
    }
};
