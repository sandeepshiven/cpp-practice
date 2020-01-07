#include<bits/stdc++.h>
using namespace std;

void transpose(int, int, vector<vector<int>> &);
void reverse_row(int, int, vector<vector<int>> &);
void print_mat(int, int, vector<vector<int>> &);

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
    reverse_row(row,column,matrix);
    transpose(row,column,matrix);
    print_mat(column,row,matrix);


    return 0;
}

void transpose(int r, int c, vector<vector<int>> &mat){

    
    for(int i=0; i<r; i++){
		for(int j=i+1; j<c; j++){
			int temp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp;
		}
	}

}


void reverse_row(int r, int c, vector<vector<int>> &mat){

    for(int i=0; i<r; i++){
       
        for(int j=0; j<c/2; j++){
            int temp = mat[i][j];
            mat[i][j] = mat[i][c-j-1];
            mat[i][c-j-1] = temp;
        }
       

    }

}

void print_mat(int r, int c, vector<vector<int>> &mat){
    
    cout << "Changed matrix\n";
    for(int i=0; i<r; i++){
        for(int j=0;j<c; j++){
            cout << mat[i][j] << " ";
        }
        cout << '\n';
    }

}