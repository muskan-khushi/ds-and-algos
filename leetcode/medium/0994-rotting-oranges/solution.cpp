class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 2){
                    q.push({i,j});
                }
                else if (grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int minutes = 0;

        while (!q.empty() && fresh > 0){
            int size = q.size();

            while (size--){
                auto [r,c] = q.front();
                q.pop();

                int dr[] = {0,-1,0,1};
                int dc[] = {1,0,-1,0};

                for (int k=0; k<4; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        fresh--;
                    }
                }
            }
            minutes++;
        }

        if (fresh > 0) return -1;
        return minutes;
    }
};