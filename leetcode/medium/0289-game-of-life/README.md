# Game of Life

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

According to Wikipedia's article: "The  **Game of Life**, also known simply as  **Life**, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an `m x n` grid of cells, where each cell has an initial state:  **live**  (represented by a `1`) or  **dead**  (represented by a `0`). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

- Any live cell with fewer than two live neighbors dies as if caused by under-population.
- Any live cell with two or three live neighbors lives on to the next generation.
- Any live cell with more than three live neighbors dies, as if by over-population.
- Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the `m x n` grid `board`. In this process, births and deaths occur  **simultaneously**.

Given the current state of the `board`,  **update**  the `board` to reflect its next state.

 **Note**  that you do not need to return anything.

 

 **Example 1:** 

```
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

```

 **Example 2:** 

```
Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]

```

 

 **Constraints:** 

- m == board.length
- n == board[i].length
- 1 <= m, n <= 25
- board[i][j] is 0 or 1.

 

 **Follow up:** 

- Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
- In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.4 MB (beats 98.21%)  
**Submitted:** 2026-08-21T10:44:57.798Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/game-of-life/)