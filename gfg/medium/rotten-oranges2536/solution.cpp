class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        
        //queue to store rotten oranges
        queue<pair<int, int>> q;
        
        int fresh = 0;
        
        //track fresh and rotten oranges
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (mat[i][j] == 2){
                    q.push({i,j});
                }
                else if (mat[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        int minutes = 0;
        
        //all turns
        while (!q.empty() && fresh > 0){
            int size = q.size();
            
            //one turn -> one level of bfs
            while (size--){
                auto [r,c] = q.front();
                q.pop();
                
                int dr[] = {0, -1, 0, 1};
                int dc[] = {1, 0, -1, 0};
                
                for (int k=0; k<4; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    
                    if (nr>=0 && nr<m && nc>=0 && nc<n && mat[nr][nc] == 1){
                        mat[nr][nc] = 2;
                        q.push({nr, nc});
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