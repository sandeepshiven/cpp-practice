#include<bits/stdc++.h>

using namespace std;

struct Point{
    int x, y;
};

bool my_point(Point p1, Point p2){
    return p1.y < p2.y;
}


int main(){

    Point arr[] = {{6,8},{9,3},{4,3},{1,2},{3,7}};

    sort(arr, arr+5, my_point);
    for(auto i: arr){
        cout << i.x << ", " << i.y<<'\n';
    }
    cout << "\n";


    return 0;
}











