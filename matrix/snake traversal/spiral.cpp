#include<bits/stdc++.h>
using namespace std;

void spiral_travel(int, int, vector<vector<int>> &);


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
    spiral_travel(row,column,matrix);


    return 0;
}

void spiral_travel(int r, int c, vector<vector<int>> &mat){

    cout << "The spiral matrix\n";
    for(int i=0; i<mat.size(); i++){
        if((i+1)%2 != 0){
        for(int j=0; j<mat[i].size(); j++){
            cout << mat[i][j] << " ";
        }
        }
        else{
            for(int j=mat.size()-1; j>=0; j--){
            cout << mat[i][j] << " ";
        }
        }
        cout << "\n";

    }

}