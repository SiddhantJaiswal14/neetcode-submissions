class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    bool isValid(int i, int j, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || grid[i][j] == '0' || grid[i][j] == '#')
            return false;
        return true;
    }
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(!isValid(i,j,grid))
            return;
        grid[i][j] = '#';
        for(int k=0; k<4; k++)
            dfs(i+dx[k], j+dy[k], grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int islands = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(i,j,grid);
                }
            }
        }

        return islands;
    }
};
