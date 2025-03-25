#include <iostream>
using namespace std;
// We will create a helper function to check if a given cell/position
// is safe to move or not..!!
bool isPathSafe(int** arr, int x, int y, int n){
    if(x < n && y < n && arr[x][y] == 1){
        return true;
    }
    return false;
}

// Recursive fuction to find the path for the Rat in the Maze
// We will initially take a resultant array with all zeroes
// We will keep updating the resultant array as we get the coordinates

bool ratInMaze(int** arr, int x, int y, int n, int** resultantArray){
    // Base Case "If the rat has already reached it's destination"
    if( x == (n-1) && y == (n-1)){
        resultantArray[x][y] = 1; // Mark the destination as reached [1]
        return true;
    }

    // Check if the current position is safe to stand
    if(isPathSafe(arr,x,y,n)){
        resultantArray[x][y] = 1; // Mark the current position in the o/p

        // Move forward / right to check if path is found
        if(ratInMaze(arr,x+1,y,n,resultantArray)){
            return true;
        }
        // Move downward / bottom to check if path is found
        if(ratInMaze(arr,x,y+1,n,resultantArray)){
            return true;
        }
        // We are traversing back because no path was found..!!
        // So, we backtrack and update the path to [x][y] = 0;
        resultantArray[x][y] = 0; // Backtracking
        // If no path is found, it is invalid
        return false;
    }
    return false;
}
int main(){
    int n;
    cout << "Enter the value of n:" << endl;
    cin >> n;
    // Dynamically allocate memory for the 2D Maze Array
    int ** arr = new int * [n]; // Rows
    // For each row we need to allocate memory dynamically [cols]
    for(int i=0; i<n; ++i){
        arr[i] = new int[n]; // Columns
    }
    // Input the maze array values
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> arr[i][j];
        }
    }

    // Dynamically allocate memory for the resultant array and assign 0s
    int ** resultantArray = new int *[n];
    for(int i=0; i<n; ++i){
        resultantArray[i] = new int[n];
        for(int j=0; j<n; ++j){
            resultantArray[i][j] = 0; // Initialise to all zeroes
        }
    }
    // Call the ratInMaze() function to find the path in the Maze
    if(ratInMaze(arr,0,0,n,resultantArray)){
        // If true, we have a path stored in the resultant array
        // So we print the resultant array
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                cout << resultantArray[i][j] <<  " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "No path for the Rat In The Maze exists." << endl;
    }

    // Deallocate the memory after use
    for(int i=0; i<n; i++){
        delete[] arr[i];
        delete[] resultantArray[i];
    }
    delete[] arr;
    delete[] resultantArray;

    return 0;
}

