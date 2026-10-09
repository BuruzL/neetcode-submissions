class Solution {
public:
    
bool isValid(int l, int m, int x, int y){
    if(x>=l || x<0 || y>=m || y<0)return false;
    return true;
}

void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int sr, int sc){
    queue<pair<int, int>> q;
        q.push({sr,sc});
        vis[sr][sc] = 0;
         int dirX[4]={0,0,1,-1};
        int dirY[4]={1,-1,0,0};

        int l=grid.size();
        int m=grid[0].size();

        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int nr=r+dirX[i];
                int nc=c+dirY[i];

                if(isValid(l,m,nr,nc) && grid[nr][nc]=='1' && vis[nr][nc]!=0){
                    vis[nr][nc]=0;
                    q.push({nr, nc});
                }
            }
        }
}

int numIslands(vector<vector<char>>& grid) {
   

        int l=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(l, vector<int> (m, -1));

        
        int ctr=0;

        for(int i=0; i<l; i++ ){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && vis[i][j]!=0){
                    ctr++;
                    bfs(grid, vis, i,j);
                }
            }
        }

        return ctr;
    }
};
