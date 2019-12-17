#include<bits/stdc++.h>
using namespace std;

void transpose(int, int, vector<vector<int>> &);


int main(){

    int row;
    int column;
    cout << "Enter the number of rows: ";
    cin >> row;

    cout << "Enter the number of columns: ";
    cin >> column;
    vector<vector<int>> matrix(row, vector<int>(column));
    for(int i=0; i<row; i++){
        cout << "Enter row "<< i+1 << "\n";
        for(int j=0; j<column; j++){
            cin >> matrix[i][j];
        }

    }
    transpose(row,column,matrix);


    return 0;
}

void transpose(int r, int c, vector<vector<int>> &mat){

    cout << "The transpose of matrix\n";
    for(int i=0; i<c; i++){
       
        for(int j=0; j<r; j++){
            cout << mat[j][i] << " ";
        }
       
        cout << "\n";

    }

}