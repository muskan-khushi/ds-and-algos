class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                int live = 0;

                for (int k=0; k<8; k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr >=0 && nr <n && nc >=0 && nc < m){
                        if (board[nr][nc] == 1 || board[nr][nc] == 2){
                            live++;
                        }
                    }
                }

                if (board[i][j] == 1){
                    if (live < 2 || live > 3){
                        board[i][j] = 2;
                    }
                }

                else if (board[i][j] == 0){
                    if (live == 3){
                        board[i][j] = 3;
                    }
                }
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (board[i][j] == 2) board[i][j] = 0;
                else if (board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};