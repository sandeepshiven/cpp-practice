#include<bits/stdc++.h>

using namespace std;




int findLargestArea(vector<int>&arr){

    // https://www.hackerrank.com/challenges/largest-rectangle/editorial


    stack<int>s;
    arr.push_back(0);
    int i=0;
    int res = 0;

    while(i<arr.size()){

        if(s.empty() || (arr[i] > arr[s.top()]) ){

            s.push(i);
            i++;

        }
        else{
            int p = s.top();
            s.pop();
            int curr = arr[p]*((s.empty()?i: (i-s.top()-1)));
            res = max(res, curr); 
        }

    }

    return res;

}

int findLargestRectangle(vector<vector<int>>&arr){

    int res = findLargestArea(arr[0]);

    for(int i=1; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            if(arr[i][j]==1){
                arr[i][j] += arr[i-1][j];
            }
        }
        res = max(res, findLargestArea(arr[i]));
    }

    return res;


}







int main(){

    cout << "Enter the number of rows: ";
    int r;
    cin >> r;
    cout << "Enter the number of columns: ";
    int c;
    cin >>c;
    vector<vector<int>> vec(r, vector<int>(c));
    for(auto i = 0; i<r; i++){
        cout << "Enter elements of row "<<i+1<<": ";
        for(int j=0; j<c; j++){
            cin >> vec[i][j];
        }
    }
    cout << "Largest Rectangle with all 1's is: "<< findLargestRectangle(vec)<<'\n';


    return 0;
}