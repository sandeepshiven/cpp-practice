#include<bits/stdc++.h>
using namespace std;

void boundary(int, int, vector<vector<int>> &);


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
    boundary(row,column,matrix);
    cout << '\n';

    return 0;
}

void boundary(int r, int c, vector<vector<int>> &mat){
    cout << "The boundary is:\n";
    for(int i=0; i<c; i++)
        cout << mat[0][i] << " ";

    for(int i=1; i<r; i++)
        cout << mat[i][c-1] << " ";

    for(int i=c-2; i>=0; i--)
        cout << mat[r-1][i] << " ";

    for(int i=r-2; i>0; i--)
        cout << mat[i][0] << " ";

}