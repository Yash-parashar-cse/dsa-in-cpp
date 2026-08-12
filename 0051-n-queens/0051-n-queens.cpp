class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col, int n){
        // check horizontally
        for(int i=0; i<n; i++){
            if(board[row][i] == 'Q'){
                return false;
            }
        }

        // Check vertically
        for(int j=0; j<n; j++){
            if(board[j][col] == 'Q'){
                return false;
            }
        }

        // Check for left upper diagonal
        for(int k=row, l=col; k>=0 && l>=0; k--,l--){
            if(board[k][l] == 'Q') return false;
        }

        // Check for right upper diagonal
        for(int k=row, l=col; k>=0 && l<n; k--,l++){
            if(board[k][l] == 'Q') return false;
        }

        return true;
    }
    void nQueen(vector<string> &board, int row, int n, vector<vector<string>> &ans){

        // base case
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int j=0; j<n; j++){
            if(isSafe(board, row, j, n)){

                board[row][j] = 'Q';
                nQueen(board, row+1, n, ans);

                // Backtrack
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string>> ans;

        nQueen(board, 0, n, ans);
        return ans;
    }
};