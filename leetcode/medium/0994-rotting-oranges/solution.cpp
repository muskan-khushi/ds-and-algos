class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        //to store rotten oranges
        queue<pair<int, int>> q;

        //to store fresh count
        int fresh = 0;

        //storing rotten oranges in queue and tracking fresh count
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

        //initializing minutes
        int minutes = 0;

        //all turns
        while (!q.empty() && fresh > 0){
            int size = q.size();

            //one turn -> one level
            while (size--){
                auto [r,c] = q.front();
                q.pop();

                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};

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