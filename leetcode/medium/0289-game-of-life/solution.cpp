class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();

        // 8 possible directions
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};


        // Visit every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int live = 0;


                // Check all 8 neighbours
                for (int k = 0; k < 8; k++) {

                    // Find neighbour's position
                    int nr = i + dr[k];
                    int nc = j + dc[k];


                    // Check if neighbour is inside the board
                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n) {

                        /*
                            1 = originally alive
                            2 = originally alive but will die

                            So both 1 and 2 count as
                            LIVE neighbours.
                        */
                        if (board[nr][nc] == 1 ||
                            board[nr][nc] == 2) {

                            live++;
                        }
                    }
                }


                // Current cell is alive
                if (board[i][j] == 1) {

                    /*
                        Fewer than 2 OR more than 3
                        live neighbours → cell dies.

                        2 means:
                        "I was alive, but I will die."
                    */
                    if (live < 2 || live > 3) {
                        board[i][j] = 2;
                    }
                }


                // Current cell is dead
                else if (board[i][j] == 0) {

                    /*
                        Exactly 3 live neighbours
                        → dead cell becomes alive.

                        3 means:
                        "I was dead, but I will become alive."
                    */
                    if (live == 3) {
                        board[i][j] = 3;
                    }
                }
            }
        }


        // Convert temporary states to final states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Originally alive → now dead
                if (board[i][j] == 2) {
                    board[i][j] = 0;
                }

                // Originally dead → now alive
                else if (board[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};