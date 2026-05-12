class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool isValid(int i, int j, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> rotten;
        int fresh = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    rotten.push({i,j});
            }
        }

        if(fresh == 0)
            return 0;
        
        int time = 0;
        while(!rotten.empty() && fresh!=0){
            time++;
            int s = rotten.size();
            while(s--){
                auto it = rotten.front();
                rotten.pop();
                for(int k=0; k<4; k++){
                    int x = it.first + dx[k];
                    int y = it.second + dy[k];
                    if(isValid(x,y,grid) && grid[x][y] == 1){
                        grid[x][y] = 2;
                        fresh--;
                        rotten.push({x,y});
                    }
                }
            }
        }

        if(fresh != 0)
            return -1;

        return time;
    }
};
