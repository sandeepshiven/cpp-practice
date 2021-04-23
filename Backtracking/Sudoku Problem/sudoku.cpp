#include <bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<int>>&grid, int n, int i, int j, int num){

    for(int k=0; k < n; k++){
        if(grid[i][k] == num || grid[k][j] == num){
            return false;
        }
    }
    int s = sqrt(n);
    int rs = i - i%s;
    int cs = j - j%s;

    for(int i=0; i<s; i++){
        for(int j=0; j<s; j++){
            if(grid[i+rs][j+cs] == num){
                return false;
            }
        }
    }

    return true;
}


bool solve(vector<vector<int>>&grid, int n){
    
    int i, j;
    bool flag = false;
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(grid[i][j] == 0){
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }

    if(i == n && j == n){
        return true;
    }

    for(int num = 1; num <= n; num++){
        if(isSafe(grid, n, i, j, num)){
            grid[i][j] = num;
            if(solve(grid, n)){
                return true;
            }
            grid[i][j] = 0;
        }
    }
    return false;
    
}

int main(){
    int n;
    cout << "Enter the size of Sudoku: ";
    cin >> n;
    vector<vector<int>>grid(n, vector<int>(n));
    cout << "Enter the grid: \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    if(solve(grid, n)){
        cout << "YES\n";
        for(auto i: grid){
            for(auto j: i){
                cout << j << " ";
            }
            cout << '\n';
        }
    }
    else{
        cout << "NO\n";
    }
    
    return 0;
}