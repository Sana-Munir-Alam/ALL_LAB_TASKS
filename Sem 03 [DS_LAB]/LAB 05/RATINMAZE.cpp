#include <iostream>
using namespace std;

bool isSafe(int** Array, int x, int y, int n) {
    if(x >= 0 && y >= 0 && x < n && y < n && Array[x][y] == 1) {
        return true;
    }
    return false;
}

bool RatInMaze(int** Array, int x, int y, int n, int** SolArray) {
    if((x == (n-1)) && (y == (n-1))) {
        SolArray[x][y] = 1;
        return true;
    }

    if (isSafe(Array, x, y, n)) {
        SolArray[x][y] = 1;

        if (RatInMaze(Array, x+1, y, n, SolArray)) {
            return true;
        }
        if (RatInMaze(Array, x, y+1, n, SolArray)) {
            return true;
        }
        
        // Backtrack - this was missing in your original code
        SolArray[x][y] = 0;
        return false;
    }
    // THIS IS THE CRITICAL SECOND RETURN FALSE
    return false;  // If position is NOT safe
}

void printSolution(int** SolArray, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << SolArray[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of maze (n x n): ";
    cin >> n;
    
    // Create the maze array
    int** maze = new int*[n];
    for(int i = 0; i < n; i++) {
        maze[i] = new int[n];
    }
    
    // Create the solution array
    int** sol = new int*[n];
    for(int i = 0; i < n; i++) {
        sol[i] = new int[n];
        for(int j = 0; j < n; j++) {
            sol[i][j] = 0;  // Initialize with 0
        }
    }
    
    cout << "Enter the maze (1 for path, 0 for wall):" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }
    
    cout << "\nMaze:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    
    if(RatInMaze(maze, 0, 0, n, sol)) {
        cout << "\nSolution found! Path:" << endl;
        printSolution(sol, n);
    } else {
        cout << "\nNo solution exists!" << endl;
    }
    
    // Free memory
    for(int i = 0; i < n; i++) {
        delete[] maze[i];
        delete[] sol[i];
    }
    delete[] maze;
    delete[] sol;
    
    return 0;
}
