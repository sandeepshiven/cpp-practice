#include <bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, int n, vector<vector<int>>&maze){
    return (i<n && j<n && maze[i][j] == 1);
}


bool solve(vector<vector<int>>&maze, vector<vector<int>>&path, int n, int i, int j){
    if(i == n-1 && j == n-1){
        path[i][j] = 1;
        return true;
    }
    if(isSafe(i, j, n, maze)){
        path[i][j] = 1;
        if(solve(maze, path, n, i+1, j)){
            return true;
        }
        else if(solve(maze, path, n, i, j+1)){
            return true;
        }
        path[i][j]=0;
    }
    return false;
}

int main(){

    int n;
    cout << "Enter maze size: ";
    cin >> n;
    cout << "Enter maze:\n";
    vector<vector<int>>maze(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> maze[i][j];
        }
    }
    vector<vector<int>>path(n, vector<int>(n, 0));

    if(solve(maze, path, n, 0, 0)){
        cout << "YES\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << path[i][j]<<" ";
            }
           cout << '\n';
        }
    }
    else{
        cout << "NO\n";
    }
    
    return 0;
}