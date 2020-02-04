#include<bits/stdc++.h>

using namespace std;


template <class T>
T Greater(T a, T b){
    return a > b ? a :b ;
}


int main(){


    cout << "Greater of 3 and 4 is: " << Greater(3,4)<< endl;
    cout << "Greater of 3.54 and 4.435 is: " << Greater(3.54,4.435)<< endl;
    cout << "Greater of 3.1 and 3.2 is: " << Greater(3.1,3.2)<< endl;
    cout << "Greater ASCII of A and B is: " << Greater('A', 'B')<< endl;


    return 0;
}























































