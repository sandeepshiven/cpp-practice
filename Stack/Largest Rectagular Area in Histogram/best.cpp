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









int main(){

    cout << "Enter the number of bars: ";
    int s;
    cin >> s;
    vector<int>vec(s);
    cout << "Enter the values of "<<s<<" bars: ";
    for(auto i=vec.begin(); i!=vec.end(); i++){
        cin >> *i;
    }
    cout << "Largest area is: "<<findLargestArea(vec)<<'\n';


    return 0;
}