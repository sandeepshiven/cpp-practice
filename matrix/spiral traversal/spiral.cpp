#include<bits/stdc++.h>
using namespace std;

void spiral(int, int, vector<vector<int>> &);


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
    spiral(row,column,matrix);
    cout << '\n';

    return 0;
}

void spiral(int r, int c, vector<vector<int>> &mat){
    cout << "The spiral is:\n";
    int l=0, k=0;
    	/* k - starting row index 
		r - ending row index 
		l - starting column index 
		c - ending column index 
		i - iterator 
	*/
    while(l<c && k<r){

    for(int i=l; i<c; i++)
        cout << mat[k][i] << " ";
    k++;

    for(int i=k; i<r; i++)
        cout << mat[i][c-1] << " ";
    c--;

    if(k<r){

    for(int i=c-1; i>=l; i--)
        cout << mat[r-1][i] << " ";
    r--;
    }

    if(l<c){

    for(int i=r-1; i>=k; i--)
        cout << mat[i][l] << " ";
    
    l++;
    }

    }
}