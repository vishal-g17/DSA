#include <bits/stdc++.h> 
bool issafe(int row, int col, vector<vector<int>> &board, int value){
    for(int i=0;i<board.size();i++){
        //row chk
        if(board[row][i] == value){
            return false;
        }
        //col chk
        if(board[i][col] == value){
            return false;
        }
        //3*3 matrix chk
        if(board[3*(row/3) + i/3][3* (col/3) + i%3] == value){
            return false;
        }
        
    }
    return true;
}

bool solve(vector<vector<int>> &board){
    int n = board[0].size();

    for(int row =0; row<n;row++){
        for(int col =0; col<n; col++){
            //cell empty

            if(board[row][col] ==0){
                for(int val=1; val<=9;val++){

                    if(issafe(row, col, board, val)){
                        board[row][col]= val;

                        //recursive call
                        bool aagesolpossible = solve(board);
                        if(aagesolpossible){
                            return true;
                        }
                        else{
                            //backtrack
                            board[row][col] = 0;
                        }
                }
            }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}