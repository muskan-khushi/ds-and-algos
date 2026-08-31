class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[0].size(); j++){
                char num = board[i][j];
                if (num == '.') continue;
                if (rows[i].count(num)) return false;
                rows[i].insert(num);
                if (cols[j].count(num)) return false;
                cols[j].insert(num);

                int box = (i/3)*3 + j/3;
                if (boxes[box].count(num)) return false;
                boxes[box].insert(num);
            }
        }

        return true;
    }
};