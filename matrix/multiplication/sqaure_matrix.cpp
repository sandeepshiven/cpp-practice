#include<bits/stdc++.h>
using namespace std;

void mat_multiply(int, int, vector<vector<int>> &,int, int, vector<vector<int>> &);

int main(){
    cout << sizeof(int);
    int test;
    cin >> test;
    while(test--){

    //cout << "Enter no. of rows of matrix 1: ";
    int m1;
    cin >> m1;
    //cout << "Enter no. of columns of matrix 1: ";
    int n1;
    cin >> n1;
    vector<vector<int>> matrix1(m1, vector<int>(n1));

    for(int i=0; i<m1; i++){
        ////cout << "Enter row "<< i+1 << "\n";
        for(int j=0; j<n1; j++){
            cin >> matrix1[i][j];
        }

    }

    //cout << "Enter no. of rows of matrix 2: ";
    int m2;
    cin >> m2;
    //cout << "Enter no. of columns of matrix 2: ";
    int n2;
    cin >> n2;
    vector<vector<int>> matrix2(m2, vector<int>(n2));

    for(int i=0; i<m2; i++){
       // cout << "Enter row "<< i+1 << "\n";
        for(int j=0; j<n2; j++){
            cin >> matrix2[i][j];
        }

    }

    if(n1 != m2){
        cout << "Matrix cannot be multiplied!!\n";
        continue;
    }

    mat_multiply(m1, n1, matrix1, m2, n2, matrix2);
    cout << "\n";

    }


    return 0;
}



void mat_multiply(int m1, int n1, vector<vector<int>> &mat1, int m2, int n2, vector<vector<int>> &mat2){

    vector<vector<int>> result(m1, vector<int>(n2));
    for(int i=0; i<m1; i++){
        for(int j=0; j<n2; j++){
            int prod = 0;
            for(int k=0; k<n1; k++){
                prod += mat1[i][k]*mat2[k][j];
            }
            cout << prod<<" ";
        }
    }
    
}











