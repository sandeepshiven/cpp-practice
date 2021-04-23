#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>&board, int n, int i, int j){
    //check the row
    for(int k = 0; k<j; k++){
        if(board[i][k] == 1){
            return false;
        }
    }
    
    
    //check up-left diagonal
    for(int k=i-1, l=j-1; k>=0 && l>=0; k--, l--){
        if(board[k][l] == 1){
            return false;
        }
    }
    //check down-left diagonal
    for(int k=i+1, l=j-1; k<n && l>=0; k++, l--){
        if(board[k][l] == 1){
            return false;
        }
    }
   
    return true;
}

bool solve(vector<vector<int>>&board, int n, int j){

    if(j == n){
        return true;
    }

    for(int k=0; k<n; k++){
        if(isSafe(board, n, k, j)){
            board[k][j] = 1;
            if(solve(board, n, j+1)){
                return true;
            }
            board[k][j]=0;
        }
        
    }
    return false;
}

int main(){

    int n;
    cout << "Enter the size of board: ";
    cin >> n;
    vector<vector<int>>board(n, vector<int>(n, 0));
    if(solve(board, n, 0)){
        cout << "YES\n";
        for(auto i: board){
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