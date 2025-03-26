#include<bits/stdc++.h>
using namespace std;
bool isPathSafe(int row, int col, vector<vector<int>>& board, int val){
    for(int i=0; i<board.size(); i++){
        // row check
        if(board[row][i] == val){
            return false;
        }
        // column check
        if(board[i][col] == val){
            return false;
        }
        // 3x3 matrix check
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val){
            return false;
        }
    }
    return true;
}
bool solveSudoku(vector<vector<int>>& board){
    int n = board.size();
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            if(board[row][col] == 0){
                for(int val = 1; val <= 9; val++){
                    if(isPathSafe(row, col, board, val)){
                        board[row][col] = val;
                        if(solveSudoku(board)){
                            return true;
                        }else{
                            board[row][col] = 0; // Back Tracking
                        }
                    }
                }
                return false; // No valid value found for the cell 
            }
        }
    }
    return true; // All cells were successfully filled...!!! 

}
int main(){
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    if(solveSudoku(board)){
        cout << "Solution Board Found: " << endl;
        for(const auto& row : board){
            for(int num : row){
                cout << num << " ";
            }cout << endl;
        }
    }else{
        cout << "No Solution Found..!!" << endl;
    }
    return 0;
}